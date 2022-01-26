/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:26:55 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/26 12:03:20 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_infos
{
	char	c;
	int		bits;
	char	*str;
	int		pid;
}	t_infos;

void	error(int error);
int		ft_strisdigit(char *str);

#endif
