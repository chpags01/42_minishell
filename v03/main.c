/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:10 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/14 19:46:21 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	set_signal(SHE, SHE);
	// g_exit_code = 0;
	(void)argc;
	(void)argv;
}

int	main(int argc, char *argv[], char *envp[])
{
	char				*line;
	struct termios		term;
	t_cmd				*cmd;
	t_env				env_head;

	tcgetattr(STDIN_FILENO, &term);
	main_init(argc, argv);
	for (int i = 0; i < 100; i++)
	{
		// printf("%s\n", envp[i]); // to check envp
	}
	env_init(&env_head, envp);
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			break ;
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !is_whitespace(line))
		{
			cmd = ft_cmd_init();
			parse(line, cmd);
			// func for excution is needed
			ft_cmd_free(cmd);
		}
		free(line);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
