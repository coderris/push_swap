/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/10 19:31:07 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/10 19:31:07 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_reader(char const *str, va_list args, char const *holder)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_putchar_fd('%', 1);
			else
			{
				str = str + i;
				counter += ft_case(str, args) - 1;
				str = holder;
			}
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
		counter++;
	}
	return (counter);
}

int	ft_printf(char const *str, ...)
{
	va_list		args;
	int			result;
	char const	*holder;

	holder = str;
	if (!str)
		return (-1);
	va_start(args, str);
	result = ft_reader(str, args, holder);
	va_end(args);
	return (result);
}
