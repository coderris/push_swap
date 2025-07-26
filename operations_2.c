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

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}
void 	r(t_stack **stack, char *c)
{
	rotate(stack);
	ft_printf("r%s\n", c);
}
void 	rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
void	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
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
}
void 	rr(t_stack **stack, char *c)
{
	reverse_stack(stack);
	ft_printf("rr%s\n", c);
}
void	reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	reverse_stack(stack_a);
	reverse_stack(stack_b);
	ft_printf("rrr\n");
}