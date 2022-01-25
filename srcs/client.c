/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:28:57 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/25 17:58:28 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	t_infos g_infos;

static void	kill_to_server(int signum, int pid)
{
	if (kill(pid, signum) == -1)
		error(0);
}

static int	kill_null(int pid)
{
	size_t	i;

	i = 0;
	while (i <= 7)
	{
		kill_to_server(SIGUSR1, pid);
		usleep(500);
		i++;
	}
	return (1);
}

// This is the function that sends the message in binary to the server on SIGUSR1 and SIGUSR2
static void	my_handler_to_binary(pid_t pid, char *str)
{
	int	i;
	int	shift;

	i = 0;
	while (str[i])
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] & (1 << shift)))
				kill_to_server(SIGUSR1, pid);
			else
				kill_to_server(SIGUSR2, pid);
		usleep(1000);
		shift--;
		}
		i++;
	}
	kill_null(pid);
}

// This is the function that recieves the signal from the server for the bonus
static void	signal_handler(int signum)
{
	static int	bool = 1;

	if (signum == SIGUSR1 && bool)
		bool = 0;
	if (signum == SIGUSR2)
	{
		bool = 1;
		exit (0);
	}
}

int	main(int ac, char **av)
{
	if (ac == 3 && ft_isdigit(ft_atoi(av[1])))
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		g_infos.pid = ft_atoi(av[1]);
		my_handler_to_binary(ft_atoi(av[1]), av[2]);
		while (1);
	}
	else
		return (0);
}
