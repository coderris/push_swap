/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:33:01 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/17 13:33:01 by lanton-m         ###   ########.fr       */
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
	if (stack && stack->next)
	{
		swap(&stack->content, &stack->next->content);
		ft_printf("s%s\n", c);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	a_swapped;
	int	b_swapped;

	a_swapped = 0;
	b_swapped = 0;
	if (stack_a && stack_a->next)
	{
		swap(&stack_a->content, &stack_a->next->content);
		a_swapped = 1;
	}
	if (stack_b && stack_b->next)
	{
		swap(&stack_b->content, &stack_b->next->content);
		b_swapped = 1;
	}
	if (a_swapped || b_swapped)
		ft_printf("ss\n");
}

int	push(t_stack **dst, t_stack **src)
{
	t_stack	*aux;

	if (src && *src)
	{
		aux = *src;
		*src = (*src)->next;
		aux->next = *dst;
		*dst = aux;
		return (1);
	}
	return (0);
}

void	p(t_stack **stack_1, t_stack **stack_2, char *c)
{
	if (push(stack_1, stack_2))
		ft_printf("p%s\n", c);
}
