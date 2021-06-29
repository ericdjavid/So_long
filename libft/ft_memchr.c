/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:47:06 by edjavid           #+#    #+#             */
/*   Updated: 2020/11/24 10:47:10 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	int			i;

	i = 0;
	str = (const char*)s;
	while (n--)
	{
		if (str[i] == (char)c)
			return ((void*)&str[i]);
		i++;
	}
	return (0);
}
