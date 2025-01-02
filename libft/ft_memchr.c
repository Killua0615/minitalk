/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:10:44 by nateshim          #+#    #+#             */
/*   Updated: 2024/10/25 19:24:54 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	data = (unsigned char *)s;
	while (i < n)
	{
		if (data[i] == (unsigned char)c)
			return ((void *)(data + i));
		i++;
	}
	return (NULL);
}
