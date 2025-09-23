/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:23:56 by lanton-m          #+#    #+#             */
/*   Updated: 2025/06/21 19:10:11 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				idx;
	struct s_stack	*next;
}	t_stack;

int		ft_valid_input(char **splited_values);
int		ft_valid_int(char *str);
int		*ft_to_int(char **values, int size);
int		is_sorted(t_stack *stack);
int		ft_stacksize(t_stack *lst);
char	**ft_fill_stack(int arguments, char **values);
char	**ft_strjoin_array(char **old_result, char **list);
int		ft_count_strings(char **arr);
long	ft_atoi_safe(char *str);
int		ft_duplicates(int *values, int size);
void	ft_error_exit(void);
void	ft_free_split(char **str);
void	swap(int *a, int *b);
void	s(t_stack *stack, char *c);
void	ss(t_stack *stack_a, t_stack *stack_b);
int		push(t_stack **dst, t_stack **src);
void	p(t_stack **stack_1, t_stack **stack_2, char *c);
int		rotate(t_stack **stack_a);
void	r(t_stack **stack, char *c);
int		rotate_all(t_stack **stack_a, t_stack **stack_b);
int		reverse_stack(t_stack **stack);
void	rr(t_stack **stack, char *c);
int		reverse_all(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b, int size);
int		ft_val_size(char **values);
int		assign_indexes(t_stack *stack, int *values, int size);
void	fast_ord(t_stack **stack_a, t_stack **stack_b, int size);
t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
int		stack_creation(int *values, int size, t_stack **stack_a);
void	move_min_to_top(t_stack **a, int size);
int		get_min_position(t_stack *stack);
void	free_stack(t_stack **stack);
void	free_all_stack(t_stack **stack_1, t_stack **stack_2);
void	ft_error_exit_free(char **splited, int *values);
void	push_chunks(t_stack **a, t_stack **b, int size, int chunks);
int		find_max_position(t_stack *stack);
void	sort_b_to_a(t_stack **a, t_stack **b);
void	hybrid_sort(t_stack **a, t_stack **b, int size);
void	free_partial_array(char **arr, int count);
void	ft_error_exit_complete(char **splited, int *values,
			t_stack **stack_a, t_stack **stack_b);

#endif