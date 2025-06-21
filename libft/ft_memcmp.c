/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:42:30 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/09/29 19:45:14 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s_1;
	const char	*s_2;
	size_t		i;
	int			aux;

	s_1 = s1;
	s_2 = s2;
	aux = 0;
	i = 0;
	while (aux == 0 && i < n)
	{
		aux = (unsigned char)s_1[i] - (unsigned char)s_2[i];
		i++;
	}
	return (aux);
}
