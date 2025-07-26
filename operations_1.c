/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:24:36 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/26 20:54:25 by lanton-m         ###   ########.fr       */
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
	ft_printf("s%s\n", c);
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
