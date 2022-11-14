/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:22 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/14 19:46:19 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <stdlib.h>

// int	g_exit_code;

typedef struct s_cmd
{
	char			**argv;
	int				argc;
	bool			is_pipe;
	bool			is_dollar;
	int				fd[2];
	int				infile;
	int				outfile;
	char			*cmd_path;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}						t_cmd;

void		*ft_free(void *ptr);
t_cmd		*ft_cmd_init(void);
void		ft_cmd_free(t_cmd *cmd);

#endif
