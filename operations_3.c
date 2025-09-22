/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:00:00 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/21 00:00:00 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack, char *c)
{
	if (reverse_stack(stack))
		ft_printf("rr%s\n", c);
}

int	reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	int	da;
	int	db;

	da = reverse_stack(stack_a);
	db = reverse_stack(stack_b);
	if (da || db)
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
