/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:46:53 by edjavid           #+#    #+#             */
/*   Updated: 2020/11/30 10:46:56 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*src_p;
	unsigned char	*dest_p;

	src_p = (unsigned char *)src;
	dest_p = (unsigned char*)dest;
	while (src_p && n > 0)
	{
		*dest_p = *src_p;
		if (*src_p == (unsigned char)c)
			return ((void*)dest_p + 1);
		dest_p++;
		src_p++;
		n--;
	}
	return (NULL);
}
