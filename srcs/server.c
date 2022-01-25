/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:28:55 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/25 18:13:14 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	t_infos g_char;

static void	struct_init(void)
{
	g_char.c = 0;
	g_char.bits = 7;
}

static char	*received_string(char *str)
{
	ft_printf("\nPID [");
	ft_printf("%d ] :", g_char.pid);
	if (!str)
		ft_printf("\n");
	else
		ft_printf("%s\n", str);
	free(g_char.str);
	return (NULL);
}

static void	kill_to_client(int signum)
{
	if (kill(g_char.pid, signum) == -1)
		error (1);
}

//	The handler will print every binary sent into a character and send back a signal to the client
//	to acknowledge it has been clearly received
//	The siginfo structure is passed as a second parameter to a user signal handler function whenever the SA_SIGINFO flag was
//	specified. The void *context points to the structure of a signal that was saved (unsused here)
static void	my_handler_to_char(int signum, siginfo_t *siginfo, void *context)
{
	int	bit;

	(void)context;
	if (siginfo->si_pid)
		g_char.pid = siginfo->si_pid;
	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_char.c += g_char.bits;
	g_char.bits--;
	if(g_char.bits > 0)
	{
		if (!g_char.c)
		{
			g_char.str = received_string(g_char.str);
			kill_to_client(SIGUSR2);
		}
		else
			g_char.str = ft_strjoin_char(g_char.str, g_char.c); // append char;
		struct_init();
	}
	kill_to_client(SIGUSR1);
}

	//intialize our sa_mask to null
	//add SIGUSR1 to our sigaction struct so it's recognized (returns -1 on error)
	//add SIGUSR2 to our sigaction struct so it's recognize (returns -1 on error)
	// when SA_SIGINFO is specified in sa_flags :
	// sa_mask specifies a mask of signals which should be blocked
	// sa_sigaction specifies the signal handling function for signum
	// sa_flags specifies a set of flags which modify the behavior of the signal
	//sigaction takes the signum, the sigaction in use, and old sigaction (unused here)
int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	struct sigaction	sa;
	if (ac != 1)
		return (0);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = my_handler_to_char;
	struct_init();
	g_char.str = NULL;
	ft_printf("Server opened with PID : %d\n", getpid());
	ft_putendl_fd("|----------------------------------|", 1);
	ft_putendl_fd("|         **INSTRUCTIONS**         |", 1);
	ft_putendl_fd("|   Open a new terminal and run:   |", 1);
	ft_printf("|  ./client %d \"sample string\"   |\n", getpid());
	ft_putendl_fd("| Press CTRL+C to close the server |", 1);
	ft_putendl_fd("|----------------------------------|", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1);
}
