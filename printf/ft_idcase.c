/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idcase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/23 18:58:04 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/23 19:55:36 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_idcase(int num)
{
	char	*ptr;
	int		len;

	ptr = ft_itoa(num);
	if (!ptr)
		return (0);
	len = ft_strlen(ptr);
	write(1, ptr, len);
	free(ptr);
	return (len);
}
