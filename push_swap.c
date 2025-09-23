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

static int	*validate_and_convert(char **splited_values, int values_size)
{
	int	*values;

	if (ft_valid_input(splited_values) == 1)
		ft_error_exit_free(splited_values, NULL);
	values = (int *)ft_to_int(splited_values, values_size);
	if (!values)
		ft_error_exit_free(splited_values, NULL);
	ft_free_split(splited_values);
	if (ft_duplicates(values, values_size))
		ft_error_exit_free(NULL, values);
	return (values);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b,
				char **splited_values)
{
	int	*values;
	int	values_size;
	int	size;

	if (!splited_values)
		ft_error_exit();
	values_size = ft_val_size(splited_values);
	values = validate_and_convert(splited_values, values_size);
	if (!values)
		ft_error_exit_free(splited_values, NULL);
	stack_creation(values, values_size, stack_a);
	assign_indexes(*stack_a, values, values_size);
	if (is_sorted(*stack_a))
	{
		free(values);
		free_all_stack(stack_a, stack_b);
		return ;
	}
	size = ft_stacksize(*stack_a);
	hybrid_sort(stack_a, stack_b, size);
	free(values);
}

int	main(int argc, char **argv)
{
	char	**splited_values;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		splited_values = ft_fill_stack(argc - 1, argv + 1);
		push_swap(&stack_a, &stack_b, splited_values);
	}
	free_all_stack(&stack_a, &stack_b);
	return (0);
}
