/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:52:23 by lanton-m@st       #+#    #+#             */
/*   Updated: 2024/11/02 20:18:34 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	if (size_dst >= size)
		size_dst = size;
	if (size_dst == size)
		return (size_dst + size_src);
	else if (size > (size_src + size_dst))
		ft_memcpy(dst + size_dst, src, size_src + 1);
	else
	{
		ft_memcpy(dst + size_dst, src, size - size_dst - 1);
		dst[size - 1] = '\0';
	}
	return (size_src + size_dst);
}
