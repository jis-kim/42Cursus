/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:24:37 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/17 15:43:00 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	s_size;
	unsigned int	index;
	char			*result;

	if (!s)
		return (NULL);
	s_size = (unsigned int)ft_strlen(s);
	index = 0;
	result = malloc(sizeof(char) * (s_size + 1));
	if (!result)
		return (NULL);
	while (index < s_size)
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[s_size] = '\0';
	return (result);
}
