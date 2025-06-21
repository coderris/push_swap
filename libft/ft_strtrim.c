/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:02:23 by lanton-m          #+#    #+#             */
/*   Updated: 2024/10/31 21:17:19 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numelemfront(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (set[j] == s1[i])
		{
			counter += 1;
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (counter);
}

static size_t	ft_numelemback(char const *s1, char const *set, size_t length)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (s1[length - 1 - i] != '\0' && set[j] != '\0')
	{
		if (set[j] == s1[length - 1 - i])
		{
			counter += 1;
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (counter);
}

static char	*ft_trimmer(char const *s1, size_t s1_length, size_t upfront,
		size_t last)
{
	size_t	i;
	char	*str;

	i = 0;
	if (upfront == s1_length && last == s1_length)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
		return (str);
	}
	str = malloc(s1_length - upfront - last + 1);
	if (!str)
		return (NULL);
	while (i < (s1_length - upfront - last))
	{
		str[i] = (char)s1[upfront + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_length;
	size_t	upfront;
	size_t	last;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	s1_length = ft_strlen(s1);
	upfront = ft_numelemfront(s1, set);
	last = ft_numelemback(s1, set, s1_length);
	return (ft_trimmer(s1, s1_length, upfront, last));
}
