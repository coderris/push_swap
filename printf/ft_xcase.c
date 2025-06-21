/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/24 12:39:17 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/24 12:39:17 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xcase(unsigned int num, int n)
{
	ft_putnbr_x_fd(num, 1, n);
	return (ft_times_hex(num));
}
