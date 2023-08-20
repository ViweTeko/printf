#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format specifier
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int i = 0;

	va_list type;

	va_start(type, format);
	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(type, int));
					break;
				case 's':
					{
					char *str = (va_arg(type, char *));

					while (*str)
					{
						_putchar (*str);
						str++;
					}
					break;
					}
				case '%':
					_putchar(37);
					break;

				default:
					_putchar(format[i]);
					break;
			}
			i++;
		}
	}
	va_end(type);
	_putchar('\n');
	return (0);
}

/**
 * print_rev_str - prints reverse string according to format specifier
 * @format: format specifier
 * Return: 0
 */

int print_rev_str(const char *format, ...)
{
	int i = 0;

	va_list type;

	va_start(type, format);
	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'r':
					{
					char *rev = (va_arg(type, char *));
					int s;

					while (*rev)
					{
					for (s = 0; rev[s] != '\0'; ++s)
					{
					}
					for (s -= 1; s >= 0; --s)
						{
							_putchar((int)rev[s]);
						}
					}
					break;
					}

				default:
					putchar(format[i]);
					break;
			}
			i++;
		}
	}
	va_end(type);
	putchar('\n');
	return (0);
}
