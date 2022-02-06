/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:13:27 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/07 01:54:40 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	split_len(char const *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 1;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		else
		{
			if (flag)
				count++;
			flag = 0;
		}
		s++;
	}
	return (count);
}

static	const char	*create_ele(char **array, const char *s, char c, size_t i)
{
	const char	*tmp;
	size_t		size;
	char		*element;
	size_t		index;

	tmp = s;
	size = 0;
	index = 0;
	while (*tmp != c && *tmp)
	{
		size++;
		tmp++;
	}
	element = malloc(sizeof(char) * (size + 1));
	if (!element)
		exit(1);
	array[i] = element;
	while (*s != c && *s && index < size)
		element[index++] = *s++;
	element[index] = 0;
	return (--s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	index;
	int		flag;

	if (!s)
		return (NULL);
	result = ft_calloc((split_len(s, c) + 1), sizeof(char *));
	if (!result)
		exit(1);
	index = 0;
	flag = 1;
	while (*s)
	{
		if (flag && *s != c)
			s = create_ele(result, s, c, index++);
		flag = (*s == c);
		s++;
	}
	return (result);
}
