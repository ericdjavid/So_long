/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:46:35 by edjavid           #+#    #+#             */
/*   Updated: 2020/11/30 10:46:38 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_p;
	char		*dest_p;

	src_p = (char *)src;
	dest_p = (char*)dest;
	while (src_p && n > 0)
	{
		*dest_p = *src_p;
		dest_p++;
		src_p++;
		n--;
	}
	return (dest);
}
