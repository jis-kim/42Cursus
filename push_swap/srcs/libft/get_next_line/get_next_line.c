/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:56:00 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 17:09:15 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char		*join;
	char		*tmp;
	char const	*s1_tmp;

	if (!s1 || !s2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	join = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	tmp = join;
	s1_tmp = s1;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	free((void *)s1_tmp);
	return (join);
}

static int	buf_split(char **buf_remain, char **line, int check_read)
{
	char	*tmp;
	char	*buf_newline;

	if (*buf_remain == NULL)
		*buf_remain = ft_strdup("");
	buf_newline = ft_strchr(*buf_remain, '\n');
	if (buf_newline)
	{
		*buf_newline++ = '\0';
		*line = ft_strdup(*buf_remain);
		tmp = *buf_remain;
		*buf_remain = ft_strdup(buf_newline);
		free(tmp);
		return (1);
	}
	else if (check_read == 0 && !buf_newline)
	{
		*line = *buf_remain;
		*buf_remain = NULL;
	}
	return (0);
}

int	ft_free(int ret_val, char *buf)
{
	free(buf);
	return (ret_val);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*buf_remain;
	ssize_t		check_read;
	int			success;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| read(fd, *line, 0) == -1)
		return (-1);
	buf = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1);
	success = buf_split(&buf_remain, line, 1);
	if (success != 0)
		return (ft_free(success, buf));
	check_read = read(fd, buf, BUFFER_SIZE);
	while (check_read > 0)
	{
		buf[check_read] = '\0';
		buf_remain = ft_strjoin_free(buf_remain, buf);
		success = buf_split(&buf_remain, line, check_read);
		if (success != 0)
			return (ft_free(success, buf));
		check_read = read(fd, buf, BUFFER_SIZE);
	}
	if (check_read == 0)
		return (ft_free(buf_split(&buf_remain, line, check_read), buf));
	return (check_read);
}
