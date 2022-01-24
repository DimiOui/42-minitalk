/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:28:57 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/24 18:35:13 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	t_infos g_infos;

// This is the function that sends the message in binary to the server on SIGUSR1 and SIGUSR2
void	my_handler_to_binary(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{
			kill(pid, SIGUSR1);
			usleep(1000);
		}
		if (str[i] == 'b')
		{
			kill(pid, SIGUSR2);
			usleep(1000);
		}
	i++;
	}
}

// This is the function that recieves the signal from the server for the bonus
void	signal_handler(int signum)
{
	static int	bool = 1;

	if (signum == SIGUSR1 && bool)
	{
		bool = 0;
	}
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
		return (4);
}
