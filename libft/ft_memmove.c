/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:47:13 by edjavid           #+#    #+#             */
/*   Updated: 2020/12/13 15:04:14 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_p;
	unsigned char	*dest_p;
	char			temp[n];
	size_t			i;

	if (!dest && !src)
		return (NULL);
	src_p = (unsigned char *)src;
	dest_p = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		temp[i] = src_p[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_p[i] = temp[i];
		i++;
	}
	return (dest);
}
