/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:23:29 by nateshim          #+#    #+#             */
/*   Updated: 2024/11/14 11:30:34 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_x(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_x(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putnbr_xx(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_xx(n / 16);
	count += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	return (count + ft_putnbr_x(ptr));
}
