/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:50:19 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/13 11:50:19 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag_pid[2] = {};

static char	*print_line(char *line, int size)
{
	write(1, line, size);
	if (line)
		free(line);
	line = NULL;
	return (NULL);
}

static char	*make_line(char *line, char sym, int size)
{
	char	*new_line;
	int		i;

	i = 0;
	if (sym == '\0')
		return (print_line(line, size - 1));
	new_line = (char *)malloc(sizeof(char) * (size + 1));
	if (!new_line)
		err_exit("Malloc error");
	if (size != 1)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;
		}
		if (line)
			free(line);
		line = NULL;
	}
	new_line[i] = sym;
	new_line[++i] = '\0';
	return (new_line);
}

static void	on_get_signal(int signum, siginfo_t *sig_info, void *context)
{
	static t_line	ln;

	(void)context;
	if (ln.ndig == 0)
	{
		ln.ndig = 65536;
		ln.sym = 0;
	}
	if (signum == SIGUSR1)
	{
		ln.sym = ln.sym + ln.ndig;
		ln.ndig = ln.ndig >> 1;
	}
	else
		ln.ndig = ln.ndig >> 1;
	if (ln.ndig == 0)
	{
		ln.size++;
		ln.line = make_line(ln.line, ln.sym, ln.size);
		if (ln.sym == '\0')
			ln.size = 0;
	}
	g_flag_pid[1] = sig_info->si_pid;
	g_flag_pid[0] = 1;
}

int	main(void)
{
	struct sigaction	handler;

	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	handler.sa_flags = SA_SIGINFO;
	handler.sa_sigaction = on_get_signal;
	if (sigaction(SIGUSR1, &handler, 0) == -1
		|| sigaction(SIGUSR2, &handler, 0) == -1)
		err_exit("Sigaction error!");
	while (1)
	{
		while (g_flag_pid[0] != 1)
		{
		}
		g_flag_pid[0] = 0;
		kill(g_flag_pid[1], SIGUSR1);
	}
}
