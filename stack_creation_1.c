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
	char	**old_result;

	i = 0;
	result = NULL;
	while (i < arguments)
	{
		list = ft_split(values[i], ' ');
		if (!list)
		{
			ft_free_split(result);
			return (NULL);
		}
		old_result = result;
		result = ft_strjoin_array(result, list);
		ft_free_split(old_result);
		ft_free_split(list);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

static int	copy_old_strings_safe(char **result, char **old_result, int len1)
{
	int	i;

	i = 0;
	while (i < len1)
	{
		result[i] = ft_strdup(old_result[i]);
		if (!result[i])
		{
			free_partial_array(result, i);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	copy_new_strings_safe(char **result, char **list,
								int len1, int len2)
{
	int	i;

	i = 0;
	while (i < len2)
	{
		result[len1 + i] = ft_strdup(list[i]);
		if (!result[len1 + i])
		{
			free_partial_array(result + len1, i);
			free_partial_array(result, len1);
			return (0);
		}
		i++;
	}
	return (1);
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
		return (NULL);
	if (!copy_old_strings_safe(result, old_result, len1)
		|| !copy_new_strings_safe(result, list, len1, len2))
	{
		free(result);
		return (NULL);
	}
	result[len1 + len2] = NULL;
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
