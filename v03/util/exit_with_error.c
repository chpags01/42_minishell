/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan-hpa <chan-hpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:04:24 by chan-hpa          #+#    #+#             */
/*   Updated: 2022/09/21 18:18:43 by chan-hpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	exit_with_err(char *str1, char *str2, int exit_code)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	if (str2)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(str2, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(exit_code);
}

void	print_err3(char *cmd, char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (str1)
	{
		ft_putstr_fd(str1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_err(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_err2(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_quote_err3(char *cmd, char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (str1)
	{
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(str1, STDERR_FILENO);
		ft_putstr_fd("'", STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
