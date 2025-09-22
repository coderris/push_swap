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
	int		i;
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

static void	copy_old_strings(char **result, char **old_result, int len1)
{
	int	i;

	i = 0;
	while (i < len1)
	{
		result[i] = ft_strdup(old_result[i]);
		i++;
	}
}

static void	copy_new_strings(char **result, char **list, int len1, int len2)
{
	int	j;

	j = 0;
	while (j < len2)
	{
		result[len1 + j] = ft_strdup(list[j]);
		j++;
	}
}

char	**ft_strjoin_array(char **old_result, char **list)
{
	int		len1;
	int		len2;
	char	**result;

	len1 = ft_count_strings(old_result);
	len2 = ft_count_strings(list);
	result = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!result)
		exit(1);
	copy_old_strings(result, old_result, len1);
	copy_new_strings(result, list, len1, len2);
	result[len1 + len2] = NULL;
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
