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


int	ft_stacksize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	int_cmp(const void *a, const void *b)
{
	const int ia = *(const int *)a;
	const int ib = *(const int *)b;
	return (ia > ib) - (ia < ib);
}

void	assign_indexes(t_stack *stack, int *values, int size)
{
	int		*sorted;
	int		i;
	t_stack	*tmp;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		sorted[i] = values[i];
		i++;
	}
	qsort(sorted, size, sizeof(int), int_cmp);
	tmp = stack;
	while (tmp)
	{
		int *found = bsearch(&tmp->content, sorted, size, sizeof(int), int_cmp);
		if (!found)
		{
			free(sorted);
			exit(EXIT_FAILURE);
		}
		tmp->idx = (int)(found - sorted);
		tmp = tmp->next;
	}
	free(sorted);
}