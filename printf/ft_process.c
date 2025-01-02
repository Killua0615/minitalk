/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:19:36 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/07 22:21:54 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_format(const char **format, va_list ap)
{
	char	c;
	int		total;

	total = 0;
	c = **format;
	(*format)++;
	if (c == 'd' || c == 'i')
		total += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		total += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		total += ft_putnbr_x(va_arg(ap, unsigned int));
	else if (c == 'X')
		total += ft_putnbr_xx(va_arg(ap, unsigned int));
	else if (c == 's')
		total += ft_putstr(va_arg(ap, char *));
	else if (c == 'c')
		total += ft_putchar(va_arg(ap, int));
	else if (c == 'p')
		total += ft_putptr((unsigned long long)va_arg(ap, void *));
	else if (c == '%')
		total += ft_putchar('%');
	return (total);
}
