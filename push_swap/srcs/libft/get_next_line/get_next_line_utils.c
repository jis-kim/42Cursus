/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:56:13 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:53:06 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char		*join;
	char		*tmp;
	char const	*s1_tmp;

	if (!s1 || !s2)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	join = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	tmp = join;
	s1_tmp = s1;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	free((void *)s1_tmp);
	return (join);
}
