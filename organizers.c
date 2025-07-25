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
void sort_five(t_stack **a, t_stack **b)
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

// Encuentra la posición del máximo índice en stack
int find_max_position(t_stack *stack)
{
    int max = stack->idx;
    int max_pos = 0;
    int i = 0;
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

// Push chunks desde a a b con optimización de rotaciones en a
void push_chunks(t_stack **a, t_stack **b, int size, int chunks)
{
    int chunk_size = size / chunks;
    int min_idx = 0;
    int max_idx = chunk_size;

    while (min_idx < size)
    {
        int len_a = ft_stacksize(*a);
        int i = 0;
        while (i < len_a)
        {
            t_stack *tmp = *a;
            if (tmp->idx >= min_idx && tmp->idx < max_idx)
            {
                p(b, a, "b");
                if ((*b)->idx < min_idx + chunk_size / 2)
                    r(b, "b");
                i = -1;
                len_a = ft_stacksize(*a);
            }
            else
            {
                int pos = 0;
                t_stack *search = *a;
                int size_a = ft_stacksize(*a);
                while (search && !(search->idx >= min_idx && search->idx < max_idx))
                {
                    search = search->next;
                    pos++;
                }
                if (pos > size_a / 2)
                    rr(a, "a");
                else
                    r(a, "a");
            }
            i++;
        }
        min_idx += chunk_size;
        max_idx += chunk_size;
        if (max_idx > size)
            max_idx = size;
    }
}

// Decide si se puede rotar simultáneamente ambos stacks para optimizar movimientos
static int should_rotate_both(t_stack *a, t_stack *b)
{
    if (!a || !a->next || !b || !b->next)
        return 0;
    // Ejemplo: rotar ambos si ambos tienen top dos elementos en orden que beneficiaría
    // Aquí puedes mejorar la lógica según tu criterio
    if (a->idx > a->next->idx && b->idx < b->next->idx)
        return 1;
    return 0;
}

static int should_reverse_rotate_both(t_stack *a, t_stack *b)
{
    if (!a || !a->next || !b || !b->next)
        return 0;
    // Similar al anterior, con reversa
    if (a->idx < a->next->idx && b->idx > b->next->idx)
        return 1;
    return 0;
}

// Saca de b a a ordenando maximos, rotando a y b simultáneamente cuando conviene
void sort_b_to_a(t_stack **a, t_stack **b)
{
    int max_pos;
    int size;

    while (*b)
    {
        max_pos = find_max_position(*b);
        size = ft_stacksize(*b);

        if (max_pos <= size / 2)
        {
            while (max_pos-- > 0)
            {
                if (should_rotate_both(*a, *b))
                    rotate_all(a, b);
                else
                    r(b, "b");
            }
        }
        else
        {
            max_pos = size - max_pos;
            while (max_pos-- > 0)
            {
                if (should_reverse_rotate_both(*a, *b))
                    reverse_all(a, b);
                else
                    rr(b, "b");
            }
        }
        p(a, b, "a");
    }
}

// Ordena con chunking + ordenación de b optimizada
void hybrid_sort(t_stack **a, t_stack **b, int size)
{
    int chunks = 10; // Ajusta entre 6-10 para 100 números (prueba para mejor resultado)

    push_chunks(a, b, size, chunks);
    sort_b_to_a(a, b);
}
