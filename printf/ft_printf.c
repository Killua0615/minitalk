/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:05:07 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/14 15:21:43 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	char	c;

	va_start(ap, format);
	total = 0;
	while (*format)
	{
		c = *format++;
		if (c == '%')
			total += process_format(&format, ap);
		else
			total += ft_putchar(c);
	}
	va_end(ap);
	return (total);
}
