/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:02:06 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/26 14:02:06 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sorted_array(int *values, int size)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		sorted[i] = values[i];
		i++;
	}
	bubble_sort(sorted, size);
	return (sorted);
}

static int	find_index(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indexes(t_stack *stack, int *values, int size)
{
	int		*sorted;
	t_stack	*tmp;
	int		index;

	sorted = create_sorted_array(values, size);
	tmp = stack;
	while (tmp)
	{
		index = find_index(tmp->content, sorted, size);
		if (index == -1)
		{
			free(sorted);
			ft_error_exit();
		}
		tmp->idx = index;
		tmp = tmp->next;
	}
	free(sorted);
}
