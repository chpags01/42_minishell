/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:48 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/14 19:46:16 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../struct/struct.h"
# include "../util/util.h"
# include "../env/env.h"
# include "stdio.h" // should be removed before submission

char	**ft_split_argc(char const *s, char c, int *argc);
char	*ft_strjoin_char(char *s1, char s2);
int		parse_set_quotes(char line, int quotes, t_cmd *cmd);
void	parse(char *line, t_cmd *cmd);
void	argc_checker(t_cmd **cmd);
void	argv_change(t_cmd *cmd, char *new, int i);

#endif
