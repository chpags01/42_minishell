/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:51:27 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/25 21:31:30 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_line translate(t_cmd *cmd)
{
    int     idx;
    t_cmd	*ptr_cmd;
    t_line	ptr_line;

    idx = 0;
    ptr_cmd = cmd;
    while (ptr_cmd)
    {
        idx++;
        ptr_cmd = ptr_cmd->next;
    }
    ptr_line.size = idx;
    ptr_line.progs = (t_prog *)malloc(sizeof(t_prog) * ptr_line.size);
    idx = 0;
    ptr_cmd = cmd;
    while (ptr_cmd)
    {
        for (int i = 0; i < ptr_cmd->argc; i++)
        {
            ptr_line.progs[idx].args[i] =  ft_strdup(ptr_cmd->argv[i]);
            printf("%s\n", ptr_line.progs[idx].args[i]);
        }
        idx++;
        ptr_cmd = ptr_cmd->next;
    }

    return (ptr_line);
}