/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:52:49 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/01/25 18:10:25 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*char_to_str(char c)
{
	char	*new_string;

	new_string = malloc(2 * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[0] = c;
	new_string[1] = '\0';
	return (new_string);
}

char	*ft_strjoin_char(char *str, char c)
{
	size_t	i;
	char	*new_string;

	i = 0;
	if (!c)
		return (NULL);
	if (!str)
	{
		return (char_to_str(c));
	}
	new_string = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!new_string)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		new_string[i] = str[i];
		i++;
	}
	free(str);
	new_string[i] = c;
	new_string[i + 1] = '\0';
	return (new_string);
}
/* **************************************************************************
Strjoin is a function that concatenate 2 strings into one string.
°************************************************************************** */
