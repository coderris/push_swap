/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/23 18:47:16 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/23 19:48:49 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pcase(void *ptr)
{
	uintptr_t	ptr_numb;
	int			a;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	ptr_numb = (uintptr_t)ptr;
	a = ft_putstr_fd("0x", 1);
	ft_putnbr_hex_fd(ptr_numb, 1, 1);
	return (ft_times_hex(ptr_numb) + a);
}
