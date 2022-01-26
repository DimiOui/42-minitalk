/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:52:49 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/01/26 11:52:09 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*char_to_str(char c)
{
	char	*target;

	target = malloc(2 * sizeof(char));
	if (!target)
		return (NULL);
	target[0] = c;
	target[1] = '\0';
	return (target);
}

char	*ft_strjoin_char(char *str, char c)
{
	size_t	i;
	size_t	len;
	char	*target;

	i = 0;
	if (!c)
		return (NULL);
	if (!str)
		return (char_to_str(c));
	len = ft_strlen(str) + 2;
	target = malloc(sizeof(char) * len);
	if (!target)
		return (NULL);
	while (str[i])
	{
		target[i] = str[i];
		i++;
	}
	target[i] = c;
	target[i + 1] = '\0';
	return (target);
}
/* **************************************************************************
Strjoin is a function that concatenate 1 string and 1 char into one string.
°************************************************************************** */
