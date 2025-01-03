/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:33:49 by natsumi           #+#    #+#             */
/*   Updated: 2025/01/04 02:28:46 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	transmit_message(int pid, char *msg)
{
	int	bit_pos;
	int	char_pos;

	char_pos = 0;
	while (msg[char_pos])
	{
		bit_pos = 7;
		while (bit_pos >= 0)
		{
			if ((msg[char_pos] >> bit_pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_pos--;
			usleep(100);
		}
		char_pos++;
	}
	bit_pos = 8;
	while (bit_pos--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Error: Invalid argument count\n");
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	msg = argv[2];
	if (!msg[0])
	{
		ft_printf("Error: Empty message\n");
		return (1);
	}
	transmit_message(pid, msg);
	return (0);
}
