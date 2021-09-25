/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 03:41:38 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/25 16:40:35 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_space(int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
	{
		write(1, " ", 1);
		count++;
	}
	return (count);
}

int	ft_print_zero(int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
	{
		write(1, "0", 1);
		count++;
	}
	return (count);
}

int	ft_print_sign(t_format_option *opt, int value)
{
	int		ret;
	char	sign;

	ret = 1;
	if (opt->type == 'p' || (ft_strchr("xX", opt->type) && opt->flag_hash))
	{
		if (ft_strchr("xp", opt->type))
			write(1, "0x", 2);
		else if (opt->type == 'X')
			write(1, "0X", 2);
		return (2);
	}
	else if (value < 0)
		sign = '-';
	else if (opt->flag_plus)
		sign = '+';
	else if (opt->flag_space)
		sign = ' ';
	else
		ret = 0;
	write(1, &sign, ret);
	return (ret);
}
