/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:56:13 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/16 16:00:47 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char		*join;
	char		*tmp;
	char const	*s1_tmp;

	if (!s1 || !s2)
		print_error("Invalid String.");
	join = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
