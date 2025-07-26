/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizers_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:50:01 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/26 13:50:01 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (size <= 5)
		fast_ord(a, b, size);
	else
	{
		if (!a || !*a || size <= 1)
			return;
		int chunks = (size <= 100) ? 4 : 20;
		push_chunks(a, b, size, chunks);
		sort_b_to_a(a, b);
	}
}
void	fast_ord(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 1)
		exit(1);
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			s(*stack_a, "a");
	}
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b);
}