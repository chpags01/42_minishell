/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:41:40 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/19 13:37:19 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../utiles/utiles.h"
# include "../struct/struct.h"

extern int g_exit_code;


t_env	*dup_env_list(t_env *cur);
t_env	*sort_env_list(t_env *head);
void	free_env_list(t_env *env);

int		check_valid_identifier(int argc, char *argv[]);
int		is_all_digit(char *key_value, char set);
int		is_have_space(char *key_value, char set);
int		is_have_specific_char(char *key_value, char c);

int		init_env_list(t_env *cur, char **envp);
t_env	*new_env(char *key_value);
char	*get_env_key(char *key_value);
char	*get_env_value(char *key_value);
t_env	*compare_env_key(t_env *env_head, char *key);
char	*ft_getenv(t_env *env_head, char *key);

#endif
