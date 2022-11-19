/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:08:36 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/19 12:46:59 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./env.h"

char	*ft_getenv(t_env *env_head, char *key)
{
	t_env	*cur;

	cur = compare_env_key(env_head, key);
	return (cur->value);
}
