/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:08:59 by nateshim          #+#    #+#             */
/*   Updated: 2024/10/30 01:13:41 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	target;
	char	*last;

	target = (char)c;
	i = 0;
	last = NULL;
	while (s[i] != 0)
	{
		if (s[i] == target)
			last = (&(s[i]));
		i++;
	}
	if (s[i] == target)
		last = &(s[i]);
	return (last);
}
