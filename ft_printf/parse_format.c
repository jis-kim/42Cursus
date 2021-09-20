/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 06:35:39 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/21 06:35:47 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(const char **format, t_format_option *options)
{
	while (ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			options->flag_minus = 1;
		else if (**format == '0')
			options->flag_zero = 1;
		else if (**format == '#')
			options->flag_hash = 1;
		else if (**format == ' ')
			options->flag_space = 1;
		else if (**format == '+')
			options->flag_plus = 1;
		(*format)++;
	}
}

/* after check flags */
static void	check_width_precision(const char **format, t_format_option *options)
{
	if (ft_isdigit(**format))
		options->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
		options->precision = ft_atoi(++(*format));
	else
		options->precision = -1;
	while (ft_isdigit(**format))
		(*format)++;
}

static void	check_type(const char **format, t_format_option *options)
{
	if (ft_strchr("cspdiuxX%", **format))
		options->type = **format;
	(*format)++;
}

void	parse_format(const char **format, t_format_option *options)
{
	(*format)++;
	ft_bzero(options, sizeof(t_format_option));
	check_flags(format, options);
	check_width_precision(format, options);
	check_type(format, options);
}
