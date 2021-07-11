/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 10:34:16 by edjavid           #+#    #+#             */
/*   Updated: 2020/12/13 14:55:06 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	s;
	char			*ptr;

	s = nmemb * size;
	ptr = malloc(s);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, s);
	return (ptr);
}
