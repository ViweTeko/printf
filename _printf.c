#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			i++;
			format++;
		}
		else
		{
			format++;

			if  (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				i++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len] != '\0')
					{
						len++;
					}
				write(1, str, len);
				i += len;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				i++;
				format++;

			}

			else
			{
				write (1, "Unsupported format specifier: ", 30);
				write(1, format, 1);
				i +=31;
			}
			format++;
		}
	}
	va_end(args);
	return(i);
}
