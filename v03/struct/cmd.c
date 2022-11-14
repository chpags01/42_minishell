/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:00:29 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/14 19:46:17 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	*ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
	return (NULL);
}

t_cmd	*ft_cmd_init(void)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	new_cmd->argc = 0;
	new_cmd->argv = NULL;
	new_cmd->is_dollar = false;
	new_cmd->fd[0] = -2;
	new_cmd->fd[1] = -2;
	new_cmd->infile = -2;
	new_cmd->outfile = -2;
	new_cmd->cmd_path = NULL;
	new_cmd->is_pipe = false;
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	return (new_cmd);
}

void	ft_cmd_free(t_cmd *cmd)
{
	t_cmd	*ptr;
	int		i;

	while (cmd)
	{
		i = 0;
		while (i < cmd->argc)
		{
			cmd->argv[i] = ft_free(cmd->argv[i]);
			i++;
		}
		cmd->argv = ft_free(cmd->argv);
		ptr = cmd;
		cmd = cmd->next;
		ptr = ft_free(ptr);
	}
}
