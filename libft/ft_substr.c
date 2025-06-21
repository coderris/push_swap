/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:03:00 by lanton-m          #+#    #+#             */
/*   Updated: 2024/10/31 20:35:39 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_str(char const *s, size_t text_len, unsigned int start,
		size_t len)
{
	size_t	i;
	char	*aux;

	i = 0;
	if (start >= text_len)
	{
		aux = malloc(1);
		if (!aux)
			return (NULL);
		aux[0] = '\0';
		return (aux);
	}
	if (len > text_len - start)
		len = text_len - start;
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	while (i < len)
	{
		aux[i] = s[i + start];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	text_len;

	if (!s)
		return (NULL);
	text_len = ft_strlen(s);
	return (new_str(s, text_len, start, len));
}
