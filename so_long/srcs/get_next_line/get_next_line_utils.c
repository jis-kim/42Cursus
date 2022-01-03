/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:56:13 by jiskim            #+#    #+#             */
/*   Updated: 2022/01/04 00:41:37 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	char		*tmp;
	char const	*s1_tmp;

	if (!s1 || !s2)
		print_error("Invalid String.");
	join = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*temp;

	dest = (char *)ft_calloc(ft_strlen(src) + 1);
	temp = dest;
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (dest);
}
