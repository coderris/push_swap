/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:09:03 by lanton-m          #+#    #+#             */
/*   Updated: 2025/06/15 19:11:27 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
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
	exit(1);
}
void	free_all_stack(t_stack **stack_1, t_stack **stack_2)
{
	free_stack(stack_1);
	free_stack(stack_2);
	exit(0);
}