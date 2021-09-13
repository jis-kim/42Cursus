#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

static	int printf_error(t_format_option *options)
{
	free(options);
	return (-1);
}

static	void check_flags(const char **format, t_format_option *options)
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

static int check_width_precision(const char **format, t_format_option *options)
{
	const char	*width_end;

	while(!ft_strchr("diuxXpcs%", **format)) //type 만나는 순간 끝남
	{
		if (**format == '.') //precision 있음
			width_end = *format - 1; //. 전까지가 precision
		if (**format == '\0') //문자열이 끝남 -> %는 나왔는데 해당 타입이 없음
			return (printf_error(options));
	}
	return 0;
}

static	t_format_option *parse_format(const char **format)
{
	t_format_option	*options;
	int	width_index;

	options = NULL;
	ft_bzero(options, sizeof(t_format_option));
	check_flags(format, options);
	check_width_precision(format, options);
	return (options);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				ret;
	t_format_option	*parsed;

	ret = 0;
	va_start(ap, format);

	while (*format != 0)
	{
		//%를 만나면
		if (*format == '%')
		{
			format++;
			parsed = parse_format(&format);
		}
		else
		{
			write(1, format++, 1);
			ret++;
		}
	}
	return (0);
}

int main(void)
{
	// printf("%-d\n", -2147483648); //-2147483648
	// printf("%04d\n", -4); //-004
	// printf("%.4d\n", -4); //-0004
	// printf("%+x\n", 1024); //undefined behavior
	// printf("%+d\n", 1024); //+1024
	// printf("% d\n", 1024); // 1024
	// printf("%+u\n", 1024);
	// printf("%-d\n", 1024); //1024 양수면 - 무시
	//printf("%a"); //컴파일 안됨
	// printf("%12+d", 123); //여러개 있으면 하나로 처리 +가 가장 먼저 처리된다고 경고 뜸
	// printf("%2147.121", 1234);
	// printf("%+-+-+-   10d",1234); //+1234

	return (0);
}
