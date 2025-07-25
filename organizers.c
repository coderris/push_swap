/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:50:58 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/24 11:50:58 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a = (*stack)->content;
	int	b = (*stack)->next->content;
	int	c = (*stack)->next->next->content;

	if (a > b && b < c && a < c)
		s(*stack, "a");
	else if (a > b && b > c)
	{
		s(*stack, "a");
		r(stack, "a");
	}
	else if (a > b && b < c && a > c)
		r(stack, "a");
	else if (a < b && b > c && a < c)
	{
		s(*stack, "a");
		r(stack, "a");
	}
	else if (a < b && b > c && a > c)
		rr(stack, "a");
}
void    sort_five(t_stack **a, t_stack **b)
{
    int size = ft_stacksize(*a);

    while (size > 3)
    {
        move_min_to_top(a);
        // Si ambos stacks tienen el siguiente par desordenado, hacer ss
        if ((*a)->next && (*a)->content > (*a)->next->content
            && *b && (*b)->next && (*b)->content < (*b)->next->content)
            ss(*a, *b);
        else
            p(b, a, "b");
        size--;
    }
    sort_three(a);

    while (*b)
        p(a, b, "a");
}
int	    find_closest_chunk_pos(t_stack *stack, int min, int max)
{
	int i = 0;
	t_stack *tmp = stack;

	while (tmp)
	{
		if (tmp->idx >= min && tmp->idx < max)
			return i;
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
int	    find_max_position(t_stack *stack)
{
	int i = 0, max_pos = 0, max = stack->idx;
	t_stack *tmp = stack;
	while (tmp)
	{
		if (tmp->idx > max)
		{
			max = tmp->idx;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return max_pos;
}
void	push_chunks(t_stack **a, t_stack **b, int size, int chunks)
{
	int chunk_size = size / chunks;
	int min = 0, max = chunk_size;

	while (min < size)
	{
		int pos;
		while ((pos = find_closest_chunk_pos(*a, min, max)) != -1)
		{
			int len = ft_stacksize(*a);
			if (pos <= len / 2)
				while (pos-- > 0)
					r(a, "a");
			else
				while (pos++ < len)
					rr(a, "a");

			p(b, a, "b");

			if (*b && (*b)->idx < min + (chunk_size / 2))
				r(b, "b");
		}
		min += chunk_size;
		max += chunk_size;
		if (max > size)
			max = size;
	}
}
void	sort_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		int max_pos = find_max_position(*b);
		int size = ft_stacksize(*b);
		int moves = size - max_pos;

		if (max_pos <= size / 2)
			while (max_pos-- > 0)
				r(b, "b");
		else
			while (moves-- > 0)
				rr(b, "b");

		p(a, b, "a");
	}
}
void	hybrid_sort(t_stack **a, t_stack **b, int size)
{
	if (!a || !*a || size <= 1)
		return;
	int chunks = (size <= 100) ? 4 : 20;
	push_chunks(a, b, size, chunks);
	sort_b_to_a(a, b);
}