/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:29:07 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/06 16:52:27 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	void	insert_num(char *s, int n, int count)
{
	int	index;
	int	mod;

	index = count;
	while (index > 0)
	{
		mod = n % 10;
		if (mod < 0)
			mod *= -1;
		s[--index] = (mod) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		flag;

	count = count_digits(n);
	flag = 0;
	if (n < 0)
	{
		count++;
		flag = 1;
	}
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	insert_num(result, n, count);
	if (flag)
		result[0] = '-';
	result[count] = '\0';
	return (result);
}
