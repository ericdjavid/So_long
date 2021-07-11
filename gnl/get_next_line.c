/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:10:46 by edjavid           #+#    #+#             */
/*   Updated: 2021/02/22 12:49:30 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_statik(char *statik)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!statik)
		return (0);
	while (statik[i] && statik[i] != '\n')
		i++;
	if (!statik[i])
	{
		free(statik);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen(statik) - i) + 1));
	if (!rtn)
		return (0);
	i++;
	while (statik[i])
		rtn[j++] = statik[i++];
	rtn[j] = '\0';
	free(statik);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*statik;
	int				reader;

	reader = 1;
	if (fd < 0 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!has_return(statik) && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		statik = join_str(statik, buff);
	}
	free(buff);
	*line = get_line(statik);
	statik = get_statik(statik);
	if (reader == 0)
		return (0);
	return (1);
}
