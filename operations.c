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

static void	swap(int *a, int *b)

{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
static void	swap_stack(t_stack	*stack, char c)
{
	int	aux;

	if (stack->next)
		swap(&stack->content, &stack->next->content);
	ft_printf("s%c",c);
}
static void	swap_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next)
		swap(&stack_a->content, &stack_a->next->content);
	if (stack_b->next)
		swap(&stack_b->content, &stack_b->next->content);
	ft_printf("ss");
}
static void	push(t_stack **stack_a, t_stack **stack_b)
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
static void	rotate(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
}
static void rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr");
}
static void	reverse(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
	prev = NULL;	
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}
static void	reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_printf("rrr");
}