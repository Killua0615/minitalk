/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:15:16 by nateshim          #+#    #+#             */
/*   Updated: 2024/10/30 16:04:03 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = buf;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}

// int	main(void)
// {
// 	char	str[50];

// 	strcpy(str, "This is string.h library function");
// 	puts(str);
// 	ft_memset(str, '0', 7);
// 	puts(str);
// 	return (0);
// }
