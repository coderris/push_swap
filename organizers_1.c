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
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
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
		rr(stack, "a");
	}
	else if (a < b && b > c && a > c)
		rr(stack, "a");
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	while (size > 3)
	{
		move_min_to_top(a);
		p(b, a, "b");
		size--;
	}
	sort_three(a);
	while (*b)
		p(a, b, "a");
}

int	find_max_position(t_stack *stack)
{
	int		i;
	int		max_pos;
	int		max;
	t_stack	*tmp;

	i = 0;
	max_pos = 0;
	max = stack->idx;
	tmp = stack;
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
	return (max_pos);
}
