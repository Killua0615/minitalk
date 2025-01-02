/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:15:56 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/14 11:27:57 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	process_format(const char **format, va_list ap);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_x(unsigned long long ptr);
int	ft_putnbr_xx(unsigned int n);
int	ft_putptr(unsigned long long ptr);

#endif
