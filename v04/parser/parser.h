/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:46:48 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/19 12:46:03 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../struct/struct.h"
# include "../utiles/utiles.h"
# include "../env/env.h"

extern int g_exit_code;

char	**ft_split_argc(char const *s, char c, int *argc);
char	*ft_strjoin_char(char *s1, char s2);
int		parse_set_quotes(char line, int quotes, t_cmd *cmd);
void	parse(char *line, t_cmd *cmd);
void	replace(t_cmd *cmd, t_env *head);
void	delete_argv(t_cmd *cmd, int *i);
void	argc_checker(t_cmd **cmd);
void	argv_change(t_cmd *cmd, char *new, int i);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
