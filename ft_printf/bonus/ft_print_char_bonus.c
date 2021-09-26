/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:48:42 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/25 16:40:35 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_percent(t_format_option *opt)
{
	int	ret;
	int	zero;
	int	left_space;
	int	right_space;

	ret = 0;
	left_space = 0;
	right_space = 0;
	zero = 0;
	opt->length = 1;
	if (opt->flag_zero && !opt->flag_minus)
		zero = opt->width - opt->length;
	else if (opt->flag_minus)
		right_space = opt->width - opt->length;
	else
		left_space = opt->width - opt->length;
	ret += ft_print_space(left_space);
	ret += ft_print_zero(zero);
	ret += write(1, "%", 1);
	ret += ft_print_space(right_space);
	return (ret);
}

int	ft_print_string(t_format_option *opt, char *value)
{
	int	ret;
	int	zero;
	int	left_space;
	int	right_space;

	ret = 0;
	left_space = 0;
	right_space = 0;
	zero = 0;
	if (value == NULL)
		value = "(null)";
	opt->length = ft_strlen(value);
	if ((opt->precision >= 0) && (opt->precision < opt->length))
		opt->length = opt->precision;
	if (opt->flag_zero && !opt->flag_minus)
		zero = opt->width - opt->length;
	else if (opt->flag_minus)
		right_space = opt->width - opt->length;
	else
		left_space = opt->width - opt->length;
	ret += ft_print_space(left_space);
	ret += ft_print_zero(zero);
	ret += ft_putstr(value, opt->length);
	ret += ft_print_space(right_space);
	return (ret);
}

int	ft_print_char(t_format_option *opt, int value)
{
	int		ret;
	int		zero;
	int		left_space;
	int		right_space;
	char	ch_value;

	ret = 0;
	left_space = 0;
	right_space = 0;
	zero = 0;
	ch_value = (char)value;
	opt->length = 1;
	if (opt->flag_zero && !opt->flag_minus)
		zero = opt->width - opt->length;
	else if (opt->flag_minus)
		right_space = opt->width - opt->length;
	else
		left_space = opt->width - opt->length;
	ret += ft_print_space(left_space);
	ret += ft_print_zero(zero);
	ret += write(1, &ch_value, 1);
	ret += ft_print_space(right_space);
	return (ret);
}
