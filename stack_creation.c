/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:35:37 by lanton-m          #+#    #+#             */
/*   Updated: 2025/07/25 00:35:37 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_fill_stack(int arguments, char **values)
{
	int	i;
	char	**list;
	char	**result;

	i = 0;
	result = NULL;
	while (i < arguments)
	{
		list = ft_split(values[i], ' ');
		if (!list)
			exit (1);
		result = ft_strjoin_array(result, list);
		ft_free_split(list);
		i++;
	}
	return (result);
}
char	**ft_strjoin_array(char **old_result, char **list)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	**result;

	i = 0;
	j = 0;
	len1 = ft_count_strings(old_result);
	len2 = ft_count_strings(list);
	result = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!result)
		exit(1);
	while (i < len1)
	{
		result[i] = ft_strdup(old_result[i]);
		i++;
	}
	while (j < len2)
	{
		result[i + j] = ft_strdup(list[j]);
		j++;
	}
	result[i + j] = NULL;
	ft_free_split(old_result);
	return (result);
}
t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->idx = -1;
	new->next = NULL;
	return (new);
}
void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
void	stack_creation(int *values, int	size, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_stackadd_back(stack_a, ft_stacknew(values[i]));
		i++;
	}
}
int		ft_stacksize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}