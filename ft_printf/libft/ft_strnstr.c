/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:06:25 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/10 19:48:22 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (len < len_needle)
			return (0);
		if (*haystack == *needle)
		{
			if (!ft_memcmp(haystack, needle, len_needle))
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (0);
}
