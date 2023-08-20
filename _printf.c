#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

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
