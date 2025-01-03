/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natsumi <natsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:33:49 by natsumi           #+#    #+#             */
/*   Updated: 2025/01/04 04:22:04 by natsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int calc_power(int base, int exp)
{
	int result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static char *append_char(const char *str, char c)
{
	char    *new_str;
	size_t  len;
	size_t  i;

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

static char *handle_char(char *message, int ascii_val)
{
	char *new_message;

	new_message = append_char(message, ascii_val);
	if (!new_message)
	{
		free(message);
		return (NULL);
	}
	return (new_message);
}

static void handle_signal(int sig)
{
	static int  bit_count = 0;
	static int  ascii_val = 0;
	static char *message = NULL;

	if (!message && !(message = ft_strdup("")))
		return;
	if (sig == SIGUSR2)
		ascii_val += calc_power(2, 7 - bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (!(message = handle_char(message, ascii_val)))
			return;
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

int main(void)
{
	struct sigaction    sa;

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
