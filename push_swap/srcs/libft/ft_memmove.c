/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:26 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/10 15:10:21 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*dst_cast++ = *src_cast++;
	}
	else
	{
		src_cast += len - 1;
		dst_cast += len - 1;
		while (len--)
			*dst_cast-- = *src_cast--;
	}
	return (dst);
}
