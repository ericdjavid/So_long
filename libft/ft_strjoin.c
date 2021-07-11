/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:02:55 by edjavid           #+#    #+#             */
/*   Updated: 2020/12/19 11:35:55 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	ft_count(char const *s, int cnts)
{
	while (s[cnts])
		cnts++;
	return (cnts);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	cnts1;
	unsigned int	cnts2;
	unsigned int	i;
	unsigned int	j;
	char			*str;

	cnts1 = 0;
	cnts2 = 0;
	cnts1 = ft_count(s1, cnts1);
	cnts2 = ft_count(s2, cnts2);
	str = malloc(sizeof(char) * (cnts1 + cnts2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < cnts1)
		str[i] = s1[i];
	j = 0;
	while (j < cnts2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
