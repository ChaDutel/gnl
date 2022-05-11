/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:45:21 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/02/06 18:35:41 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fullstr(char *str, int fd)
{
	char	*buf;
	int		rr;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rr = 1;
	while (ft_strchr(str, '\n') == 0 && rr != 0)
	{
		rr = read(fd, buf, BUFFER_SIZE);
		if (rr < 0)
		{
			free (buf);
			return (NULL);
		}
		buf[rr] = '\0';
		str = ft_strjoingnl(str, buf);
	}
	free (buf);
	return (str);
}

char	*ft_select(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_static(char *str)
{
	int		i;
	int		j;
	char	*line;
	int		lenght;

	i = 0;
	j = 0;
	lenght = ft_strlen(str);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (lenght - i + 1));
	if (!line)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_fullstr(str, fd);
	if (!str)
		return (NULL);
	line = ft_select(str);
	str = ft_static(str);
	return (line);
}
