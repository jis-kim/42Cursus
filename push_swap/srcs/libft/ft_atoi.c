/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:51:02 by jiskim            #+#    #+#             */
/*   Updated: 2022/02/15 21:17:53 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long long	ai;

	sign = 1;
	ai = 0;
	while (*str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	i = 0;
	while (*str && ++i < 11)
	{
		if (*str < '0' || *str > '9')
			print_error();
		ai = (10 * ai) + (*str++ - '0');
	}
	if (*str || (sign == 1 && ai > INT_MAX) || (sign == -1 && ai > 2147483648))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (ai * sign);
}
