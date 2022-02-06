/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:24:12 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/06 16:53:01 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	write_remainder(int n, int fd)
{
	char	remainder_char;
	int		remainder;

	if (n == 0)
		return ;
	else
	{
		write_remainder(n / 10, fd);
		remainder = n % 10;
		if (remainder < 0)
			remainder *= -1;
		remainder_char = remainder + '0';
		write(fd, &remainder_char, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	else if (n == 0)
		write(fd, "0", 1);
	write_remainder(n, fd);
}
