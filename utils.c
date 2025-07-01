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
static int	*ft_to_int(char **values, int size)
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

static int	its_ordered(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	ft_stacksize(t_stack *lst)
{
	t_list	*aux;
	int		i;

	aux = lst;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

static void	fast_ord(t_stack **stack_a, int size)
{
	if (size == 1)
		exit(1);
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_stack(stack_a, "a");
	}
	else if (size == 3)
	


}