/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:33:49 by natsumi           #+#    #+#             */
/*   Updated: 2025/01/04 02:23:02 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	calc_power(int base, int exp)
{
	if (exp == 0)
		return (1);
	if (exp < 0)
		return (0);
	return (base * calc_power(base, exp - 1));
}

static char	*append_char(char const *str, char const c)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free((void *)str);
	return (new_str);
}

static void	handle_signal(int sig)
{
	static int	bit_count = 0;
	static int	ascii_val = 0;
	static char	*message = NULL;

	if (!message)
		message = ft_strdup("");
	if (sig == SIGUSR2)
		ascii_val += calc_power(2, 7 - bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		message = append_char(message, ascii_val);
		if (ascii_val == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		bit_count = 0;
		ascii_val = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: Failed to set SIGUSR1 handler\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Failed to set SIGUSR2 handler\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
