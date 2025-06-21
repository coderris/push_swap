/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:30:13 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/10/17 22:06:22 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*aux;
	size_t	space;
	size_t	i;

	i = 0;
	space = nmemb * size;
	aux = malloc(space);
	if (!aux)
		return (NULL);
	while (i < space)
	{
		aux[i] = 0;
		i++;
	}
	return (aux);
}
