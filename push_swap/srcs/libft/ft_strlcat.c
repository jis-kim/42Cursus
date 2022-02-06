/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:51:16 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/17 18:18:03 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = dlen;
	if (dlen > size)
		return (size + slen);
	while (*dest)
		dest++;
	if (!size)
		return (slen);
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (dlen + slen);
}
