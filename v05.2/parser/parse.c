/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:44:10 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/23 21:17:41 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*parse_in_pipe(char *str, int *pipe, t_cmd **cmd, t_cmd *next)
{
	if (*pipe == 1)
		exit_with_err("argv error", "||", 1);
	(*cmd)->is_pipe = true;
	(*cmd)->argv = ft_split_argc(str, ' ', &((*cmd)->argc));
	next = ft_list_init();
	(*cmd)->next = next;
	next->prev = (*cmd);
	(*cmd) = next;
	str = ft_free(str);
	*pipe = 1;
	return (str);
}

static char	*add_redirect_space(char *str, char *line, char c)
{
	if (c == '>')
	{
		line--;
		if (!(*line == '>' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, -76);
		line++;
		if (!(*line == '>' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
	}
	else if (c == '<')
	{
		line--;
		if (!(*line == '<' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, -74);
		line++;
		if (!(*line == '<' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
	}
	return (str);
}

static char	*parse_out_pipe(char *str, char *line, int quotes, int *pipe)
{
	if ((*line == ';' || *line == '\\') && quotes == 0)
		exit_with_err("symbol error", line, 1);
	else if (quotes != 0 && *line == ' ')
		str = ft_strjoin_char(str, -32);
	else if (quotes == 0 && ft_isspace(*line))
		str = ft_strjoin_char(str, ' ');
	else if ((*line == '>' || *line == '<') && quotes == 0)
		str = add_redirect_space(str, line, *line);
	else
	{
		str = ft_strjoin_char(str, line[0]);
		*pipe = 0;
	}
	return (str);
}

t_line	parse(char *line, t_envv *head)
{
	t_cmd	*cmd;
	t_cmd	*next;
	char	*str;
	int		quotes;
	int		pipe;
	t_line	parsed_line;

	cmd = ft_list_init();
	str = NULL;
	next = NULL;
	quotes = 0;
	pipe = 0;
	while (*line)
	{
		quotes = parse_set_quotes(*line, quotes, cmd);
		if (*line == '|' && quotes == 0)
			str = parse_in_pipe(str, &pipe, &cmd, next);
		else
			str = parse_out_pipe(str, line, quotes, &pipe);
		line++;
	}
	if (quotes != 0)
		exit_with_err("quotes error", NULL, 1);
	if (str != NULL)
	{
		cmd->argv = ft_split_argc(str, ' ', &(cmd->argc));
		str = ft_free(str);
	}	
	replace(cmd, head);
	argc_checker(&cmd);
	parsed_line = translate(cmd);
	// here you need to translate cmd to parsed_line
	ft_free_list(cmd);
	return (parsed_line);
}
