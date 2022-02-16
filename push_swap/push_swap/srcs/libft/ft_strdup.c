/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:57:27 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 19:37:20 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*temp;

	dest = (char *)ft_calloc(ft_strlen(src) + 1, 1);
	temp = dest;
	while (*src)
		*temp++ = *src++;
	return (dest);
}
