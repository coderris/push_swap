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

#include <push_swap.h>

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
static void	swap_a(t_stack	*stack)
{
	int	aux;

	if (stack->next)
		swap(&stack->content, &stack->next->content);
}
static void	swap_all(t_stack *stack_a, t_stack *stack_b)
{
	int	aux;

	if (stack_a->next)
		swap(&stack_a->content, &stack_a->next->content);
	if (stack_b->next)
		swap(&stack_b->content, &stack_b->next->content);
}

static void	push_a(t_stack **stack_a, t_stack **stack_b)
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
