/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:54:40 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/08 15:55:00 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp;

	if (!dst && !src)
		return (0);
	tmp = (unsigned char *)dst;
	while (n--)
	{
		*tmp++ = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (tmp);
		src++;
	}
	return (0);
}
