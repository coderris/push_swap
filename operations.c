/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:24:36 by lanton-m          #+#    #+#             */
/*   Updated: 2025/06/21 19:51:55 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
void	s(t_stack *stack, char *c)
{
	if (stack->next)
		swap(&stack->content, &stack->next->content);
	ft_printf("s%s\n",c);
}
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next)
		swap(&stack_a->content, &stack_a->next->content);
	if (stack_b->next)
		swap(&stack_b->content, &stack_b->next->content);
	ft_printf("ss\n");
}
void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (stack_b && *stack_b)
	{
		aux = *stack_b;
		*stack_b = (*stack_b)->next;
		aux->next = *stack_a;
		*stack_a = aux;
	}
}
void	p(t_stack **stack_1, t_stack **stack_2, char *c)
{
	push(stack_1, stack_2);
	ft_printf("p%s\n", c);
}
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