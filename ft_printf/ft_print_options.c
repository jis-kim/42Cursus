/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 03:41:38 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/21 06:50:45 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_space(int n)
{
	int	count;
	char	space;

	count = 0;
	space = ' ';
	while (n-- > 0)
	{
		write(1, &space, 1);
		count++;
	}
	return (count);
}

int	ft_print_zero(int n)
{
	int	count;
	char	zero;

	count = 0;
	zero = '0';
	while (n-- > 0)
	{
		write(1, &zero, 1);
		count++;
	}
	return (count);
}

int	ft_print_sign(t_format_option *options, int value)
{
	int	ret;
	char	sign;

	ret = 1;
	if (value < 0)
		sign = '-';
	else if (options->flag_plus)
		sign = '+';
	else if (options->flag_space)
		sign = ' ';
	else
		ret = 0;
	write(1, &sign, ret);
	return (ret);
}
