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
			
			i += spec(*format, args);
			format++;
		}
	}
	va_end(args);
	return(i);
}

int spec(char s, va_list ap)
{
	int i = 0;

	if (s == 'c')
	{
	char c = va_arg(ap, int);
		write(1, &c, 1);
		i++;
	}
	else if (s == 's')
	{
		char *str = va_arg(ap, char *);
		int len = 0;

		while (str[len] != '\0')
		{
			len++;
		}
		write(1, str, len);
		i += len;
	}
	else if (s == '%')
	{
		write(1, &s, 1);
		i++;
	}
	else
	{
		write(1, &s, 1);
		i += 2;
	}
	return (i);
}
