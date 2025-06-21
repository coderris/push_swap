/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/08 17:35:25 by lanton-m          #+#    #+#             */
/*   Updated: 2025/03/08 17:35:25 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(char const *format, ...);
int		ft_case(char const *str, va_list args);
int		ft_idcase(int num);
int		ft_scase(char *ptr);
int		ft_pcase(void *ptr);
int		ft_xcase(unsigned int num, int n);
int		ft_ucase(unsigned int num);
int		ft_times_hex(uintptr_t c);
void	ft_putnbr_hex_fd(uintptr_t c, int fd, int i);
void	ft_putnbr_x_fd(unsigned int c, int fd, int i);

#endif
