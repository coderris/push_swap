/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:14:22 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/10/26 23:00:23 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	char	*holder;
	int		i;

	holder = NULL;
	c_c = (char)c;
	i = 0;
	if (!s && c_c != '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == c_c)
			holder = (char *)s + i;
		i++;
	}
	if (s[i] == c_c)
		return ((char *)s + i);
	return (holder);
}
