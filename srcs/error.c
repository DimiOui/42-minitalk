/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:00:08 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/25 18:00:56 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(int error)
{
	if (error == 0)
	{
		ft_printf("Error | Could not send signal to server ===\n");
		ft_printf("=== Check |           [PID_number]          ===\n");
	}
	else if (error == 1)
	{
		ft_printf("=== Error encountered while");
		ft_putendl_fd(" sending signal to client ===", 2);
	}
	exit (1);
}
