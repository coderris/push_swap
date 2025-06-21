/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:08:55 by lanton-m          #+#    #+#             */
/*   Updated: 2025/06/15 19:08:56 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_strings(char **arr)
{
	int	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
static long	ft_atoi_safe(char *str)
{
	long	sign;
	long	result;
	long	final;

	result = 0;
	sign = 1;
	if (!str)
		exit(1);
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
	final = result * sign;
	if (final > INT_MAX || final < INT_MIN)
		ft_error_exit();
	return (final);
}
int	*ft_to_int(char **values, int size)
{
	int	i;
	int	j;
	int	*result;

	i = 0;
	j = 0;
	result = (int *)malloc(sizeof(int) * (size + 1));
	if (!result)
		exit(1);
	while(values[i])
	{
		result[i] = ft_atoi_safe(values[i]);
		i++;
	}
	return (result);
}
static int	ft_duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
static void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
