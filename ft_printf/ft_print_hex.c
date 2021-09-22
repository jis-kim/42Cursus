/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:49:04 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/22 20:55:16 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_putnbr_hex(char type, unsigned int value, int length)
{
	unsigned int	power_hex;
	int				quotient;
	int				ret;
	char			converted_value;

	power_hex = 1;
	ret = 0;
	while (--length > 0)
		power_hex *= 16;
	while (power_hex > 0)
	{
		quotient = value / power_hex;
		if (type == 'x')
			converted_value = "0123456789abcdef"[quotient];
		else
			converted_value = "0123456789ABCDEF"[quotient];
		write(1, &converted_value, 1);
		ret++;
		value = value % power_hex;
		power_hex /= 16;
	}
	return (ret);
}

int ft_print_hex(t_format_option *opt, unsigned int value)
{
	int	ret;
	int	zero;
	int	left_space;
	int	right_space;

	ret = 0;
	left_space = 0;
	right_space = 0;
	opt->length = get_hex_len(value);
	if (opt->flag_hash)
		opt->width -= 2;
	zero = opt->precision - opt->length;
	if (opt->precision < 0 && opt->flag_zero && !opt->flag_minus)
		zero = opt->width - opt->length;
	else if (opt->flag_minus)
		right_space = opt->width - MAX(opt->precision, opt->length);
	else
		left_space = opt->width - MAX(opt->precision, opt->length);
	ret += ft_print_space(left_space);
	if (opt->flag_hash && value != 0)
		ret += ft_print_sign(opt, value);
	ret += ft_print_zero(zero);
	ret += ft_putnbr_hex(opt->type, value, opt->length);
	ret += ft_print_space(right_space);
	return (ret);
}
