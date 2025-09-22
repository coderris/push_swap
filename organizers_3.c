/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizers_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:50:58 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/24 11:50:58 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_chunk_pos(t_stack *stack, int min, int max)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->idx >= min && tmp->idx < max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

static void	move_to_top(t_stack **a, int pos)
{
	int	len;
	int	reverse_moves;

	len = ft_stacksize(*a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			r(a, "a");
	}
	else
	{
		reverse_moves = len - pos;
		while (reverse_moves-- > 0)
			rr(a, "a");
	}
}

static void	process_chunk_element(t_stack **b, int min, int chunk_size)
{
	if (*b && (*b)->idx < min + (chunk_size / 2))
		r(b, "b");
}

void	push_chunks(t_stack **a, t_stack **b, int size, int chunks)
{
	int	chunk_size;
	int	min;
	int	max;
	int	pos;

	chunk_size = size / chunks;
	min = 0;
	max = chunk_size;
	while (min < size)
	{
		pos = find_closest_chunk_pos(*a, min, max);
		while (pos != -1)
		{
			move_to_top(a, pos);
			p(b, a, "b");
			process_chunk_element(b, min, chunk_size);
			pos = find_closest_chunk_pos(*a, min, max);
		}
		min += chunk_size;
		max += chunk_size;
		if (max > size)
			max = size;
	}
}
