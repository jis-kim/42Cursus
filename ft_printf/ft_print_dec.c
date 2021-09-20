/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:59:35 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/21 06:53:46 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_decimal_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_print_dec(t_format_option *options, int value)
{
	int	ret;
	int	zero;
	int	left_space;
	int	right_space;

	ret = 0;
	left_space = 0;
	right_space = 0;
	options->length = get_decimal_len(value);
	if (value < 0 || options->flag_plus || options->flag_space)
		options->width -= 1;
	zero = options->precision - options->length;
	if (options->precision < 0 && options->flag_zero && !options->flag_minus)
		zero = options->width - options->length;
	else if (options->flag_minus)
		right_space = options->width - options->precision - options->length;
	else
		left_space = options->width - options->precision - options->length;
	ret += ft_print_space(left_space);
	ret += ft_print_sign(options, value);
	ret += ft_print_zero(zero);
	//ret += ft_print_integer(value);
	ret += ft_print_space(right_space);
	return (ret);
}
