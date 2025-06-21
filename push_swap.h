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
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

static int	ft_valid_input(char **splited_values);
static int	ft_valid_int(char *str);
static char	**ft_fill_stack(int arguments, char **values);
static char	**ft_strjoin_array(char **old_result, char **list);
static int	ft_count_strings(char **arr);
static long	ft_atoi_safe(char *str);
static int	ft_duplicates(int *values, int size);
static void	ft_error_exit(void);
static void	ft_free_split(char **str);
#endif
