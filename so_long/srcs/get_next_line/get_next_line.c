/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:56:00 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/30 22:50:06 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	buf_split(char **buf_remain, char **line, int check_read)
{
	char	*tmp;
	char	*buf_newline;

	if (*buf_remain == NULL)
	{
		buf_remain = ft_strcup("");
		if (!(*buf_remain))
			return (-1);
	}

	if ((buf_newline = ft_strchr(*buf_remain, '\n')))
	{
		*buf_newline++ = '\0';
		*line = ft_strdup(*buf_remain);
		if (!*line)
			return (-1);
		tmp = *buf_remain;
		*buf_remain = ft_strdup(buf_newline);
		free(tmp);
		if (!(*buf_remain))
			return (-1);
		return (1);
	}
	else if (check_read == 0 && !buf_newline)
	{
		*line = *buf_remain;
		*buf_remain = NULL;
	}
	return (0);
}

int			ft_free(int ret_val, char *buf)
{
	free(buf);
	return (ret_val);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*buf_remain;
	ssize_t		check_read;
	int			success;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| read(fd, *line, 0) == -1)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((success = buf_split(&buf_remain, line, 1)) != 0)
		return (ft_free(success, buf));
	while ((check_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[check_read] = '\0';
		if (!(buf_remain = ft_strjoin(buf_remain, buf)))
			return (ft_free(-1, buf));
		if ((success = buf_split(&buf_remain, line, check_read)) != 0)
			return (ft_free(success, buf));
	}
	if (check_read == 0)
		return (ft_free(buf_split(&buf_remain, line, check_read), buf));
	return (check_read);
}
