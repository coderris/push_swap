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


int	ft_count_strings(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

long	ft_atoi_safe(char *str)
{
	long	sign;
	long	result;
	long	final;

	result = 0;
	sign = 1;
	if (!str)
		exit(EXIT_FAILURE);
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
	int	*result;

	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		exit(EXIT_FAILURE);
	for (i = 0; i < size; i++)
		result[i] = (int)ft_atoi_safe(values[i]);
	return (result);
}

void	move_min_to_top(t_stack **a)
{
	int		pos;
	int		min_pos;
	int		size;

	size = ft_stacksize(*a);
	min_pos = get_min_position(*a);
	pos = 0;
	if (min_pos <= size / 2)
	{
		while (pos++ < min_pos)
			r(a, "a");
	}
	else
	{
		while (pos++ < size - min_pos)
			rr(a, "a");
	}
}

int	get_min_position(t_stack *stack)
{
	int pos;
	int min_pos;
	int min_index;

	pos = 0;
	min_pos = 0;
	if (!stack)
		return -1;
	min_index = stack->idx;
	while (stack)
	{
		if (stack->idx < min_index)
		{
			min_index = stack->idx;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return min_pos;
}
