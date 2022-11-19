/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:10:33 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/11/19 12:13:36 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utiles.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*t1 != *t2 || !*t1 || !*t2)
			return (*t1 - *t2);
		++t1;
		++t2;
	}
	return (0);
}
