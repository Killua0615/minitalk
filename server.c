/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natsumi <natsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:33:49 by natsumi           #+#    #+#             */
/*   Updated: 2025/01/04 05:42:08 by natsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	calc_power(int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result *= 2;
		exp--;
	}
	return (result);
}

static char	*append_char(const char *str, char c)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len)
		new_str[i] = str[i];
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free((void *)str);
	return (new_str);
}

static void	process_bit(int sig, int *bit_count, int *ascii_val, char **message)
{
	if (!*message)
	{
		*message = ft_strdup("");
		if (!*message)
			return ;
	}
	if (sig == SIGUSR2)
		*ascii_val += calc_power(7 - *bit_count);
	(*bit_count)++;
}

static void	handle_signal(int sig)
{
	static int	bit_count;
	static int	ascii_val;
	static char	*message;

	process_bit(sig, &bit_count, &ascii_val, &message);
	if (bit_count == 8)
	{
		message = append_char(message, (unsigned char)ascii_val);
		if (!message)
			return ;
		if ((unsigned char)ascii_val == '\0')
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
	struct sigaction sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
		sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Failed to set signal handlers\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
