#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

// int ft_printf(const char *format, ...)
// {
// 	char	*format_ptr;
// 	va_list ap;
// 	int		ret;


// 	format_ptr = format;
// 	ret = 0;
// 	va_start(ap, format);
// 	while (*format_ptr != 0)
// 	{
// 		if (*format_ptr == '%')
// 		{
// 			if ()
// 			format_ptr = parse_format(format_ptr, );
// 		}
// 		else
// 			write(1, format_ptr, 1);
// 		format_ptr++;
// 	}
// 	return 0;
// }


int main(void)
{
	// printf("%-d\n", -2147483648); //-2147483648
	printf("%04d\n", -4); //-004
	// printf("%.4d\n", -4); //-0004
	// // printf("%+x\n", 1024); //undefined behavior
	// printf("%+d\n", 1024); //+1024
	// printf("% d\n", 1024); // 1024
	// // printf("%+u\n", 1024);
	return (0);
}
