/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:00:16 by nmoreira          #+#    #+#             */
/*   Updated: 2022/11/14 14:00:23 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line(int fd, char *buf, char *backup)
{
	int		bytesread;
	char	*tempbuf;

	bytesread = 1;
	while (bytesread != 0)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
			return (0);
		if (bytesread == 0)
			break ;
		buf[bytesread] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tempbuf = backup;
		backup = ft_strjoin(tempbuf, buf);
		free(tempbuf);
		tempbuf = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_get_line(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (line[count] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*resto[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, resto[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	resto[fd] = ft_get_line(line);
	return (line);
}
