/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:16:02 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/09/21 18:19:02 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_exist_file(char *tmp_file_name)
{
	int	fd;

	fd = open(tmp_file_name, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	else
		return (1);
}
