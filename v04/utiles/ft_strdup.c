/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:13:31 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/19 12:13:36 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utiles.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(s1);
	ret = (char *)ft_malloc(sizeof(char), (len + 1));
	tmp = ret;
	while (len--)
	{
		*tmp = *s1;
		++tmp;
		++s1;
	}
	*tmp = 0;
	return (ret);
}
