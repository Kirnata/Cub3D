/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:17:26 by ptopping          #+#    #+#             */
/*   Updated: 2022/07/16 22:40:04 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*get_next_line(int fd)
{	
	char		*line;
	int			byte_was_read;
	static char	*stat_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	byte_was_read = reading(&stat_line, fd);
	if (byte_was_read < 0)
		return (NULL);
	if (byte_was_read == 0)
	{
		line = ft_record(stat_line);
		if (!stat_line || !*stat_line)
		{
			free(stat_line);
			return (NULL);
		}
		stat_line = ft_cut_off(stat_line);
		return (line);
	}
	line = ft_record(stat_line);
	if (!line)
		return (NULL);
	stat_line = ft_cut_off(stat_line);
	return (line);
}

int	reading(char **stat_line, int fd)
{
	int		byte_was_read;
	char	*buff;

	byte_was_read = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	while (!(ft_find_endl(*stat_line)) && byte_was_read > 0)
	{
		byte_was_read = read(fd, buff, BUFFER_SIZE);
		if (byte_was_read <= 0)
			free(buff);
		if (byte_was_read < 0)
			return (-1);
		if (byte_was_read == 0)
			return (0);
		buff[byte_was_read] = '\0';
		*stat_line = ft_strjoin_gnl(*stat_line, buff);
		if (!*stat_line)
			return (-1);
	}
	free(buff);
	return (byte_was_read);
}

int	ft_find_endl(char *str)
{
	if (!str || !*str)
		return (0);
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
