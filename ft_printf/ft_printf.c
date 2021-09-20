/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:59:27 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/21 06:50:25 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_by_type(t_format_option *options, va_list ap)
{
	int	len;

	len = 0;
	if (ft_strchr("di", options->type))
		len = ft_print_dec(options, va_arg(ap, int));
	//else if (ft_strchr("xXu", options->type))
	//	len = ft_print_unsigned(options, va_arg(ap, unsigned int));
	//else if (options->type == 'c')
	//	len = ft_print_char(options, va_arg(ap, int));
	//else if (options->type == 'p')
	//	len = ft_print_pointer(options, va_arg(ap, void *));
	//else if (options->type == 's')
	//	len = ft_print_string(options, va_arg(ap, void *));
	//return (len);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	t_format_option	*options;
	int				ret;

	ret = 0;
	options = malloc(sizeof(t_format_option));
	if (!options)
		return (-1);
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			parse_format(&format, options);
			ret += print_by_type(options, ap);
		}
		else
		{
			write(1, format++, 1);
			ret++;
		}
	}
	va_end(ap);
	free(options);
	return (ret);
}

#include <stdio.h>
int main(void)
{
	ft_printf("%04d", 4);
}
