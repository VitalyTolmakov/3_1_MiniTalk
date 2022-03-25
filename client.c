/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:49:22 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/13 11:49:22 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_response = 0;

static void	on_get_response(int signum)
{
	(void)signum;
	g_response = 1;
}

static int	wait_response(void)
{
	while (g_response != 1)
	{
	}
	g_response = 0;
	return (1);
}

static int	send_signal(char ch, int pid, int n)
{
	if (ch & n)
	{
		if (kill(pid, SIGUSR1) == -1)
			err_exit("Kill error!");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			err_exit("Kill error!");
	}
	return (n);
}

static void	send_string_by_sym(int pid, char *str)
{
	int					i;
	int					n;
	struct sigaction	handler;

	i = 0;
	handler.sa_flags = 0;
	handler.sa_handler = on_get_response;
	if (sigaction(SIGUSR1, &handler, 0) == -1
		|| sigaction(SIGUSR2, &handler, 0) == -1)
		err_exit("Sigaction error!");
	while (i <= ft_strlen(str))
	{
		n = 65536;
		while (n != 0)
		{
			n = send_signal(str[i], pid, n) >> 1;
			wait_response();
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!((argv[1][i] >= '0' && argv[1][i] <= '9')
				|| argv[1][i] == '+'))
				err_exit("Invalid pid\n");
			i++;
		}
		send_string_by_sym(ft_atoi(argv[1]), argv[2]);
		return (0);
	}
	err_exit("Incorrect count arguments!\n");
}
