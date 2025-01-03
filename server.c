/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natsumi <natsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:33:49 by natsumi           #+#    #+#             */
/*   Updated: 2025/01/02 22:13:55 by natsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** 2のべき乗を計算する関数
** @param base: 底数
** @param exp: 指数
** @return: 計算結果
*/
static int	calc_power(int base, int exp)
{
	if (exp == 0)
		return (1);
	if (exp < 0)
		return (0);
	return (base * calc_power(base, exp - 1));
}

/*
** 文字列に新しい文字を追加する関数
** @param str: 元の文字列
** @param c: 追加する文字
** @return: 新しい文字列
*/
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

/*
** シグナルを受信して文字列を構築する関数
*/
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
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
		sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Failed to set up signal handlers\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
