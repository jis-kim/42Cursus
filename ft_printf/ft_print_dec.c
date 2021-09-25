/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:59:35 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/25 17:11:44 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_unsigned_len(t_format_option *opt, unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (opt->precision == 0 || opt->precision < -1)
			return (0);
		return (1);
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	get_decimal_len(t_format_option *opt, int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (opt->precision == 0 || opt->precision < -1)
			return (0);
		return (1);
	}
	if (opt->type == 'u')
		return (get_unsigned_len(opt, (unsigned int)n));
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_unsigned_putnbr(unsigned int value, int length)
{
	unsigned int	power_ten;
	int				quotient;
	int				ret;
	char			converted_value;

	power_ten = 1;
	ret = 0;
	if (length == 0)
		power_ten = 0;
	while (--length > 0)
		power_ten *= 10;
	while (power_ten > 0)
	{
		quotient = value / power_ten;
		converted_value = quotient + '0';
		write(1, &converted_value, 1);
		ret++;
		value = value % power_ten;
		power_ten /= 10;
	}
	return (ret);
}

int	ft_putnbr_dec(char type, int value, int length)
{
	int		power_ten;
	int		quotient;
	int		ret;
	char	converted_value;

	power_ten = 1;
	if (length == 0)
		power_ten = 0;
	if (type == 'u')
		return ((ft_unsigned_putnbr((unsigned int)value, length)));
	ret = 0;
	while (--length > 0)
		power_ten *= 10;
	while (power_ten > 0)
	{
		quotient = value / power_ten;
		if (quotient < 0)
			quotient *= -1;
		converted_value = quotient + '0';
		write(1, &converted_value, 1);
		ret++;
		value = value % power_ten;
		power_ten /= 10;
	}
	return (ret);
}

int	ft_print_dec(t_format_option *opt, int value)
{
	int	ret;
	int	zero;
	int	left_space;
	int	right_space;

	ret = 0;
	left_space = 0;
	right_space = 0;
	opt->length = get_decimal_len(opt, value);
	if ((value < 0 || opt->flag_plus || opt->flag_space) && opt->type != 'u')
		opt->width -= 1;
	zero = opt->precision - opt->length;
	if (opt->precision < 0 && opt->flag_zero && !opt->flag_minus)
		zero = opt->width - opt->length;
	else if (opt->flag_minus)
		right_space = opt->width - max(opt->precision, opt->length);
	else
		left_space = opt->width - max(opt->precision, opt->length);
	ret += ft_print_space(left_space);
	if (opt->type != 'u')
		ret += ft_print_sign(opt, value);
	ret += ft_print_zero(zero);
	ret += ft_putnbr_dec(opt->type, value, opt->length);
	ret += ft_print_space(right_space);
	return (ret);
}
