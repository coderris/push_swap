/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:51:19 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/10/26 23:00:08 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	int		i;

	c_c = (char)c;
	i = 0;
	if (!s && c_c != '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == c_c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c_c)
		return ((char *)s + i);
	return (NULL);
}
