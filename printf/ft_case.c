/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/10 19:32:43 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/10 19:32:43 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_case(char const *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (*str == 's')
		return (ft_scase(va_arg(args, char *)));
	if (*str == 'p')
		return (ft_pcase(va_arg(args, void *)));
	if (*str == 'd' || *str == 'i')
		return (ft_idcase(va_arg(args, int)));
	if (*str == 'u')
		return (ft_ucase(va_arg(args, unsigned int)));
	if (*str == 'x')
		return (ft_xcase(va_arg(args, unsigned int), 1));
	if (*str == 'X')
		return (ft_xcase(va_arg(args, unsigned int), 2));
	return (-1);
}
