/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:00:08 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/26 11:37:52 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(int error)
{
	if (error == 0)
	{
		ft_printf("Error 0\n");
	}
	else if (error == 1)
	{
		ft_printf("Error 1\n");
	}
	exit (1);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
