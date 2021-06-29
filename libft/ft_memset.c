/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:46:01 by edjavid           #+#    #+#             */
/*   Updated: 2020/12/13 14:55:32 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void		*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (n > 0)
	{
		p[i] = (char)c;
		i++;
		n--;
	}
	return (s);
}
