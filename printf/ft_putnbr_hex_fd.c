/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/26 12:26:37 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/26 12:26:37 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_fd(uintptr_t c, int fd, int i)
{
	char	*a;
	char	*b;

	a = "0123456789abcdef";
	b = "0123456789ABCDEF";
	if (c == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (c >= 16)
		ft_putnbr_hex_fd(c / 16, fd, i);
	if (i == 2)
		ft_putchar_fd(b[c % 16], fd);
	else
		ft_putchar_fd(a[c % 16], fd);
}
