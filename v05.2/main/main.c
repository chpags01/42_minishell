/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:10 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/21 21:00:29 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h> //for testing
#include <readline/history.h>
#include <libft/libft.h>
#include <env/env.h>
#include <parser/parser.h>
#include <interface/env.h>
#include <interface/line.h>
#include <executor/executor.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>

#define SHE 0
#define DFL 1
#define IGN 2

int	g_exit_code;

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal(int sig_int, int sig_quit)
{
	if (sig_int == IGN)
		signal(SIGINT, SIG_IGN);
	if (sig_int == DFL)
		signal(SIGINT, SIG_DFL);
	if (sig_int == SHE)
		signal(SIGINT, signal_handler);
	if (sig_quit == IGN)
		signal(SIGQUIT, SIG_IGN);
	if (sig_quit == DFL)
		signal(SIGQUIT, SIG_DFL);
	if (sig_quit == SHE)
		signal(SIGQUIT, signal_handler);
}

int	is_whitespace(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 9 && *line <= 13))
		{
			return (0);
		}
		line++;
	}
	return (1);
}

void	main_init(int argc, char *argv[])
{
	struct termios	term;
	if (argc != 1)
		exit_with_err("argument input error", NULL, 126);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
	set_signal(SHE, SHE);
	g_exit_code = 0;
	(void)argc;
	(void)argv;
}

void	display_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		ft_dprintf(1, "%s\n", env[i++]);
}

int	main(int argc, char *argv[], char *envp[])
{
	char			*line;
	t_envv			env_head;
	t_env			env;
	struct termios	term;
	t_line			parsed_line;

	tcgetattr(0, &term);
	main_init(argc, argv);
	// minish_env_init will replace init_env_list
	minish_env_init(&env, envp);
	init_env_list(&env_head, envp);
	display_env(env.vars);

	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			break ;
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !is_whitespace(line))
		{
			parsed_line = parse(line, &env_head);
			(void)parsed_line;
			// your data structure must be translated
			// to t_line struct to run executor
			// minish_execute(&env, parsed_line);
		}
		free(line);
	}
	tcsetattr(0, TCSANOW, &term);
}
