/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/23 18:53:16 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/23 19:45:19 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_scase(char *ptr)
{
	if (!ptr)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(ptr, 1));
}
