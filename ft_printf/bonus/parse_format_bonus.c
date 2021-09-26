/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 06:35:39 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/25 16:40:35 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	check_flags(const char **format, t_format_option *opt)
{
	while (ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			opt->flag_minus = 1;
		else if (**format == '0')
			opt->flag_zero = 1;
		else if (**format == '#')
			opt->flag_hash = 1;
		else if (**format == ' ')
			opt->flag_space = 1;
		else if (**format == '+')
			opt->flag_plus = 1;
		(*format)++;
	}
}

/* after check flags */
static void	check_width_precision(const char **format, t_format_option *opt)
{
	if (ft_isdigit(**format))
		opt->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
		opt->precision = ft_atoi(++(*format));
	else
		opt->precision = -1;
	while (ft_isdigit(**format))
		(*format)++;
}

static void	check_type(const char **format, t_format_option *opt)
{
	if (ft_strchr("cspdiuxX%", **format))
		opt->type = **format;
	(*format)++;
}

void	parse_format(const char **format, t_format_option *opt)
{
	(*format)++;
	ft_bzero(opt, sizeof(t_format_option));
	check_flags(format, opt);
	check_width_precision(format, opt);
	check_type(format, opt);
}
