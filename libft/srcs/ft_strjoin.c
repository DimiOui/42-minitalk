/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:52:49 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/11/29 15:14:52 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*target;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	target = malloc (sizeof (char) * len);
	if (!target)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		target[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		target[i + j] = s2[j];
		j++;
	}
	target[i + j] = '\0';
	return (target);
}

/* **************************************************************************
Strjoin is a function that concatenate 2 strings into one string.
°************************************************************************** */
