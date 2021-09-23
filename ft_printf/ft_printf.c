/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:59:27 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/23 19:06:03 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int	print_by_type(t_format_option *opt, va_list *ap)
//{
//	int len;

//	len = 0;
//	if (ft_strchr("diu", opt->type))
//		len = ft_print_dec(opt, va_arg(*ap, int));
//	else if (ft_strchr("xX", opt->type))
//		len = ft_print_hex(opt, va_arg(*ap, int));
//	else if (opt->type == 'p')
//		len = ft_print_pointer(opt, (unsigned long long)va_arg(*ap, void *));
//	////else if (opt->type == 'c')
//	//	len = ft_print_char(opt, va_arg(*ap, int));
//	//else if (opt->type == 's')
//	//	len = ft_print_string(opt, va_arg(*ap, char *));
//	return (len);
//}

//int	ft_printf(const char *format, ...)
//{
//	va_list			ap;
//	t_format_option	*opt;
//	int				ret;

//	ret = 0;
//	opt = malloc(sizeof(t_format_option));
//	if (!opt)
//		return (-1);
//	va_start(ap, format); //ap를 초기화한다.
//	while (*format != 0)
//	{
//		if (*format == '%')
//		{
//			parse_format(&format, opt);
//			ret += print_by_type(opt, &ap);
//		}
//		else
//		{
//			write(1, format++, 1);
//			ret++;
//		}
//	}
//	va_end(ap);
//	free(opt);
//	return (ret);
//}

#include <stdio.h>
int main(void)
{
	//printf("%d\n", printf("%!#$@")); //warning, 실제출력값 리턴
	//printf("%d\n", printf(" %2147483646d", 1));//출력실패! error (-1)
	//printf("%d\n", printf("??%.-2d??", 30));//warning, 그냥 나온다.
	//printf("%d\n", printf("%.2147483649d", 1));//정상출력
	//printf("%d\n", printf("%.4294967295d", 1));//1 출력, 1 리턴 (unsigned int max)
	//printf("%d\n", printf("%.4294967294d", 1)); //동일
	//printf("%d\n", printf("%.2147483699d", 1)); //동일
	//printf("%d\n", printf("%.2147483649d", 1)); //1, 1출력
	//printf("%d\n", printf("%.2147483655d", 3)); //
	//printf("%d\n", printf("%.2147483650d", 333));//둘 다 precision 무시
	//printf("%.-30d", 3);
	printf("\nreturn = %d", printf("%.2147483646d", 9));
}
