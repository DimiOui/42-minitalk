/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:28:57 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/18 16:10:56 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	client(pid_t pid, char *str)
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

int	main(int ac, char **av)
{
	(void) ac;
	client(ft_atoi(av[1]), av[2]);
}
