#include <stdarg.h>
#include <stdio.h>
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
static void check_width_precision(const char **format, t_format_option *options)
{
	if (ft_isdigit(**format))
		options->width = ft_atoi(*format);
	while(ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
		options->precision = ft_atoi(++(*format));
	while(ft_isdigit(**format))
		(*format)++;
}

static void check_type(const char **format, t_format_option *options)
{
	if(ft_strchr("cspdiuxX%", **format))
		options->type = **format;
	(*format)++;
}

static	t_format_option *parse_format(const char **format)
{
	t_format_option	*options;

	options = malloc(sizeof(t_format_option));
	ft_bzero(options, sizeof(t_format_option));
	check_flags(format, options);
	check_width_precision(format, options);
	check_type(format, options);
	return (options);
}

int	ft_printf(const char *format, ...)
{
	// va_list			ap;
	int				ret;
	t_format_option	*parsed;

	ret = 0;
	// va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			parsed = parse_format(&format); //두 문장을 같이 쓴다면 r-value라고 안된다고 한다.
		}
		else
		{
			write(1, format++, 1);
			ret++;
		}
	}
	// va_end(ap);
	return (ret);
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
	// printf("%+-+-+-10d",1234); //+1234
	// printf("%.-1s", "abcde");//warn
	ft_printf("%01234d", 1);

	return (0);
}
