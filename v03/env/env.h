/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:40:09 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/14 19:45:59 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../util/util.h"
# include "../struct/struct.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

int		env_init(t_env *cur, char **envp);
t_env	*new_env(char *key_value);
char	*get_env_key(char *key_value);
char	*get_env_value(char *key_value);
t_env	*compare_env_key(t_env *env_head, char *key);

#endif