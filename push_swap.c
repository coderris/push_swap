/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:51 by lanton-m          #+#    #+#             */
/*   Updated: 2025/06/21 19:17:11 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_val_size(char **values)
{
	int	i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}
void	fast_ord(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 1)
		exit(1);
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			s(*stack_a, "a");
	}
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b);
}
void	assign_indexes(t_stack *stack, int *values, int size)
{
	int		*sorted;
	int		i;
	int		j;
	int		k;
	int		temp;
	t_stack	*tmp;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		exit(1);
	i = 0;
	while (i < size)
	{
		sorted[i] = values[i];
		i++;
	}
	j = 0;
	while (j < size - 1)
	{
		k = 0;
		while (k < size - j - 1)
		{
			if (sorted[k] > sorted[k + 1])
			{
				temp = sorted[k];
				sorted[k] = sorted[k + 1];
				sorted[k + 1] = temp;
			}
			k++;
		}
		j++;
	}
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == sorted[i])
			{
				tmp->idx = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(sorted);
}


int	main(int argc, char** argv)
{
	char	**splited_values;
	int		*values;
	int		values_size;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	splited_values = ft_fill_stack(argc - 1, argv + 1);
	if (!splited_values)
		ft_error_exit();
	values_size = ft_val_size(splited_values);
	if(argc >= 2)
	{
		if (ft_valid_input(splited_values) == 1)
			ft_error_exit_free(splited_values, NULL);
		values = (int *)ft_to_int(splited_values, values_size);
		if (!values)
			ft_error_exit_free(splited_values, NULL);
		ft_free_split(splited_values);
		if (ft_duplicates(values, values_size))
			ft_error_exit_free(NULL, values);
		stack_creation(values, values_size, &stack_a);
		assign_indexes(stack_a, values, values_size);
		if(is_sorted(stack_a))
		{
			free_stack(&stack_a);
			free_stack(&stack_b);
			exit(0);
		}
		size = ft_stacksize(stack_a);
		if (size <= 5)
			fast_ord(&stack_a, &stack_b, size);
		else
			hybrid_sort(&stack_a, &stack_b, size);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(values);
	return (0);
}
