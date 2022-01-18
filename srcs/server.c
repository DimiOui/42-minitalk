/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:28:55 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/18 16:04:04 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("Received SIGUSR1!\n");
	}
	else
	{
		printf("Received SIGUSR2!\n");
	}
}

void	server()
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 0);
	printf(" : PID \n");
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;

	server();
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1);
}
