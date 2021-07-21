/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:57:27 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/08 15:55:16 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*temp;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (0);
	temp = dest;
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (dest);
}
