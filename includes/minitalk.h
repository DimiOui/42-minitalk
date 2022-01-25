/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:26:55 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/25 18:01:10 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

void	error(int error);
typedef struct s_infos
{
	char	c;
	int		bits;
	char	*str;
	int		pid;
}	t_infos;

#endif

