/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:47:42 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/26 13:47:42 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

void	r(t_stack **stack, char *c)
{
	if (rotate(stack))
		ft_printf("r%s\n", c);
}

int	rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	int da;
	int db;

	da = rotate(stack_a);
	db = rotate(stack_b);
	if (da || db)
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}

int	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rr(t_stack **stack, char *c)
{
	if (reverse_stack(stack))
		ft_printf("rr%s\n", c);
}

int	reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	int da;
	int db;

	da = reverse_stack(stack_a);
	db = reverse_stack(stack_b);
	if (da || db)
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}