/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:52:17 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/10/06 21:27:00 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (n[0] == 0)
		return (h);
	while (h[i] && i < len)
	{
		while (h[i + j] == n[j] && h[i + j] && i + j < len)
		{
			j++;
			if (n[j] == 0)
				return (h + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
