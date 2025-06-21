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

#include <push_swap.h>

static int	ft_val_size(char **values)
{
	int	i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}

static void	stack_creation(int *values, int	size, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(values[i]));
		i++;
	}
}
int	main(int argc, char** argv)
{
	char	**splited_values;
	int		*values;
	int		values_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	splited_values = ft_fill_stack(argc - 1, argv + 1);
	values_size = ft_val_size(splited_values);
	if(argc >= 2)
	{
		if (ft_valid_input(splited_values) == 1)
			ft_error_exit();
		values = (int *)ft_to_int(splited_values, values_size);
		ft_free_split(splited_values);
		if (ft_duplicates(values, values_size))
			ft_error_exit();
		stack_creation(values, values_size, &stack_a);
	}
	return (0);
}
