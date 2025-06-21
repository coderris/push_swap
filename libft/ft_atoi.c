/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:01:52 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/10/31 20:28:11 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_push(const char *str)
{
	const char	*holder;

	holder = str;
	while (*str < '0' || *str > '9')
	{
		if ((*str >= '\x00' && *str <= '\x08') || (*str >= '\x0E'
				&& *str <= '\x1F'))
			return (0);
		str++;
	}
	str = holder;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	str = ft_push(str);
	if (!str)
		return (result);
	if (*str == '-')
	{
		sign = (-1) * sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
