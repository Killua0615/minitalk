/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 05:11:41 by nateshim          #+#    #+#             */
/*   Updated: 2024/10/30 01:09:27 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n < -9 || n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	len = ft_numlen(n);
	nbr = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 9)
	{
		len--;
		str[len] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	len--;
	str[len] = '0' + (nbr % 10);
	return (str);
}

// int	main(void)
// {
// 	int test_values[] = {123, -123, 0, 42, -42, 1000000, -1000000};
// 	int num_tests = sizeof(test_values) / sizeof(test_values[0]);

// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		char *result = ft_itoa(test_values[i]);
// 		if (result)
// 		{
// 			printf("ft_itoa(%d) = %s\n", test_values[i], result);
// 			free(result); // Don't forget to free the allocated memory
// 		}
// 		else
// 		{
// 			printf("ft_itoa(%d) = NULL (memory allocation failed)\n",
// 				test_values[i]);
// 		}
// 	}
// 	return (0);
// }