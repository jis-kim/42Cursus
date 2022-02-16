/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:31:17 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 18:05:59 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_start_index(char const *s1, char const *s2)
{
	int	i;
	int	size;

	size = (int)ft_strlen(s1);
	i = 0;
	while (i < size)
	{
		if (!ft_strchr(s2, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static	int	get_end_index(char const *s1, char const *s2)
{
	int	i;
	int	size;

	size = (int)ft_strlen(s1);
	i = size - 1;
	while (i >= 0)
	{
		if (!ft_strrchr(s2, s1[i]))
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	start = get_start_index(s1, s2);
	end = get_end_index(s1, s2);
	if (start >= end)
		return (ft_strdup(""));
	result = ft_calloc(sizeof(char), (end - start + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	return (result);
}
