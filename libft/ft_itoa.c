/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:40:15 by lanton-m          #+#    #+#             */
/*   Updated: 2024/10/31 20:31:09 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	counter;

	counter = 0;
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

static char	*fill_str(int n, size_t sign, size_t special)
{
	char	*number;
	size_t	size;
	size_t	total_size;

	size = ft_size(n);
	number = malloc(size + sign + 1);
	if (!number)
		return (NULL);
	if (sign == 1)
		number[0] = '-';
	total_size = size + sign;
	while (n != 0 || (sign == 1 && n != 0))
	{
		total_size--;
		number[total_size] = n % 10 + '0';
		n = n / 10;
	}
	number[size + sign] = '\0';
	if (special == 1)
		number[size + sign - 1]++;
	return (number);
}

static char	*null_case(void)
{
	char	*num;

	num = malloc(2);
	if (!num)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	size_t	sign;
	size_t	special;

	sign = 0;
	special = 0;
	if (n > 2147483647 || n < (-2147483647 - 1))
		return (NULL);
	if (n == -2147483648)
	{
		n = 2147483647;
		special = 1;
		sign = 1;
	}
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	if (n == 0)
		return (null_case());
	else
		return (fill_str(n, sign, special));
}
