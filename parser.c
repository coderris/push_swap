/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:09:00 by lanton-m          #+#    #+#             */
/*   Updated: 2025/06/15 19:09:01 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_fill_stack(int arguments, char **values)
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

static char	**ft_strjoin_array(char **old_result, char **list)
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
static int	ft_valid_input(char **splited_values)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (splited_values[i])
	{
		if (ft_valid_int(splited_values[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_valid_int(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}
