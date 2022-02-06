/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:46:19 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/06 16:43:12 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + slen));
	while (slen--)
	{
		if (s[slen] == (char)c)
			return ((char *)(s + slen));
	}
	return (0);
}
