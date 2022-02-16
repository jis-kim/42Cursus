/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:41:00 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/08 18:20:24 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		slen;

	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	while (*src && 1 < dstsize--)
		*dest++ = *src++;
	*dest = '\0';
	return (slen);
}
