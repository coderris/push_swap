/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:05:41 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/23 13:05:41 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit_free(char **splited, int *values)
{
	if (splited)
		ft_free_split(splited);
	if (values)
		free(values);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_exit_complete(char **splited, int *values,
						t_stack **stack_a, t_stack **stack_b)
{
	if (splited)
		ft_free_split(splited);
	if (values)
		free(values);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
