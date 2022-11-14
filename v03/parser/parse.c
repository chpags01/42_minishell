/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:44:10 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/14 19:46:13 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*parse_out(char *str, char *line, int quotes, int *pipe)
{
	if ((*line == ';' || *line == '\\') && quotes == 0)
		exit_with_err("symbol error", line, 1);
	else if (quotes != 0 && *line == ' ')
		str = ft_strjoin_char(str, -32);
	else if (quotes == 0 && ft_isspace(*line))
		str = ft_strjoin_char(str, ' ');
	// else if for other exception handling
	else
	{
		str = ft_strjoin_char(str, line[0]);
		*pipe = 0;
	}
	return (str);
}

void	parse(char *line, t_cmd *cmd)
{
	t_cmd	*next;
	char	*str;
	int		quotes;
	int		pipe;

	str = NULL;
	next = NULL;
	quotes = 0;
	pipe = 0;
	while (*line)
	{
		// func for pipe & quotes is needed
		str = parse_out(str, line, quotes, &pipe);
		line++;
	}
	if (quotes != 0)
		exit_with_err("quotes error", NULL, 1);
	if (str != NULL)
	{
		cmd->argv = ft_split_argc(str, ' ', &(cmd->argc));
		for (int i = 0; i < cmd->argc; i++)
		{
			printf("%s\n", cmd->argv[i]); // printf for testing
		}
		str = ft_free(str);
	}
}
