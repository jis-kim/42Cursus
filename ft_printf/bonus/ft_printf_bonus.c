/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:59:27 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/25 16:40:35 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_by_type(t_format_option *opt, va_list *ap)
{
	int	len;

	len = 0;
	if (ft_strchr("diu", opt->type))
		len = ft_print_dec(opt, va_arg(*ap, int));
	else if (ft_strchr("xX", opt->type))
		len = ft_print_hex(opt, va_arg(*ap, int));
	else if (opt->type == 'p')
		len = ft_print_pointer(opt, (unsigned long long)va_arg(*ap, void *));
	else if (opt->type == 'c')
		len = ft_print_char(opt, va_arg(*ap, int));
	else if (opt->type == 's')
		len = ft_print_string(opt, va_arg(*ap, char *));
	else if (opt->type == '%')
		len = ft_print_percent(opt);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	t_format_option	*opt;
	int				ret;

	ret = 0;
	opt = malloc(sizeof(t_format_option));
	if (!opt)
		return (-1);
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			parse_format(&format, opt);
			ret += print_by_type(opt, &ap);
		}
		else
		{
			write(1, format++, 1);
			ret++;
		}
	}
	va_end(ap);
	free(opt);
	return (ret);
}
