#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - returns output according to specifier
 * @format: chararcter string
 * Return: i
 */

int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
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
	return (i);
}

/**
 * spec - checks format specifiers
 * @s: format specifier
 * @ap: argument pointer
 * Return: i
 */

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
	else if (s == 'd' || s == 'i')
	{
		int d = va_arg(ap, int);
		char num_str[15];
		int num_len = sprintf(num_str, "%d", d);

		write(1, num_str, num_len);
		i += num_len;
	}
	else
	{
		write(1, &s, 1);
		i += 2;
	}
	return (i);
}
