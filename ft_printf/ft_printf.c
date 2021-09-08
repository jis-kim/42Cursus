#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h"
#define CONVERSION = "diuxXpcs%";

char * parse_format(char * a){
	return a;
}

int ft_printf(const char *format, ...)
{
	char	*format_ptr;
	va_list ap;
	int		ret;


	format_ptr = format;
	ret = 0;
	va_start(ap, format);
	while (*format_ptr != 0)
	{
		//%를 만나면
		if (*format_ptr == '%')
		{
			//다음 글자가 conversion specifier인지 검사합니다.
			format_ptr++;
			if (ft_strchr("cspdiuxX%", *format_ptr) != NULL) //해당되는 글자가 있는 경우
				format_ptr = parse_format(format_ptr);
			else
				return (0);	//어쩌지 ㅎ
		}
		else
			write(1, format_ptr, 1);
		format_ptr++;
	}
	return 0;
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
	//printf("%a"); //컴파일 안됨

	return (0);
}
