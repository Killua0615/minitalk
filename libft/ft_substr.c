/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 05:23:40 by nateshim          #+#    #+#             */
/*   Updated: 2024/10/30 20:29:13 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	*new_str;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if ((size_t)start > str_len)
		return (ft_strdup(""));
	if (str_len - start > len)
		new_str = (char *)malloc(len + 1);
	else
		new_str = (char *)malloc(str_len - start + 1);
	if (new_str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < str_len && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
