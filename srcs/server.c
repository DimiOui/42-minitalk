/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:28:55 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/24 18:36:42 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static	t_infos g_char;

static void	struct_init(void)
{
	g_char.c = 0;
	g_char.bits = CHAR_BITS;
}

//static char	*received_string(char *str)
//{
//	ft_printf("\nPID [");
//	ft_printf("%d ] :", g_char.pid);
//	if (!str)
//		ft_printf("\n");
//	else
//		ft_printf("%s\n", str);
//	free(g_char.str);
//	return (NULL);
//}

// The handler will print every binary sent into a character and send back a signal to the client
// to acknowledge it has been clearly received
void	my_handler_to_char(int signum, siginfo_t *singinfo, void *context)
{
	(void)context;
	(void)singinfo;
	if (signum == SIGUSR1)
	{
		printf("Received SIGUSR1!\n");
	}
	else
	{
		printf("Received SIGUSR2!\n");
	}
}
//	The siginfo structure is passed as a second parameter to a user signal handler function whenever the SA_SIGINFO flag was
// specified. The void *context points to the structure of a signal that was saved (unsused here)

void	server()
{
	ft_printf("Server opened with PID : %d\n", getpid());
	ft_putendl_fd("|----------------------------------|", 1);
	ft_putendl_fd("|         **INSTRUCTIONS**         |", 1);
	ft_putendl_fd("|   Open a new terminal and run:   |", 1);
	ft_printf("|  ./client %d \"sample string\"   |\n", getpid());
	ft_putendl_fd("| Press CTRL+C to close the server |", 1);
	ft_putendl_fd("|----------------------------------|", 1);
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	struct sigaction	sa; //need to check this
	if (ac != 1)
		return(5); //make an error file
	sigemptyset(&sa.sa_mask); //intialize our sa_mask to null
	sigaddset(&sa.sa_mask, SIGUSR1); //add SIGUSR1 to our sigaction struct so it's recognized (returns -1 on error)
	sigaddset(&sa.sa_mask, SIGUSR2); //add SIGUSR2 to our sigaction struct so it's recognize (returns -1 on error)
	sa.sa_flags = SA_SIGINFO;
	// when SA_SIGINFO is specified in sa_flags :
	// sa_mask specifies a mask of signals which should be blocked
	// sa_sigaction specifies the signal handling function for signum
	// sa_flags specifies a set of flags which modify the behavior of the signal
	sa.sa_sigaction = my_handler_to_char;
	struct_init();
	g_char.str = NULL;
	server();
	sigaction(SIGUSR1, &sa, NULL); //sigaction takes the signum, the sigaction in use, and old sigaction (unused here)
	sigaction(SIGUSR2, &sa, NULL);
	while (1);
}
