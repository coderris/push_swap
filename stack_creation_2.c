/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:02:06 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/26 21:07:27 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	*copy_and_sort_array(int *values, int size)
{
	int	*sorted;
	int	i;
	int	j;
	int	k;
	int	temp;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		exit(1);
	i = -1;
	while (++i < size)
		sorted[i] = values[i];
	j = -1;
	while (++j < size)
	{
		k = -1;
		while (++k < size - j - 1)
		{
			if (sorted[k] > sorted[k + 1])
			{
				temp = sorted[k];
				sorted[k] = sorted[k + 1];
				sorted[k + 1] = temp;
			}
		}
	}
	return (sorted);
}

void	assign_indexes(t_stack *stack, int *values, int size)
{
	int		*sorted;
	int		i;
	t_stack	*tmp;

	sorted = copy_and_sort_array(values, size);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == sorted[i])
			{
				tmp->idx = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(sorted);
}
