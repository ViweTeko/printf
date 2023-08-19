#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_format - prints a format of specific function
 * @specifier: specified formatter for %
 * @ap: argument pointer
 *
 * Return: b
 */

int print_format(char specifier, va_list ap)
{
	int b;

	b = 0;
	if (specifier == 'c')
		b += _putchar(va_arg(ap, int));
	else if (specifier == 's')
		b += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		b += print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		b += print_digit((long)va_arg(ap, unsigned int), 16);
	else
	{
		_putchar('%');
		b += _putchar('r');
		b += 1;
	}
	return (b);
}

/**
 * _putchar - prints a char
 * @c: char
 *
 * Return: char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string of chars
 * @str: the string
 *
 * Return: s
 */
int print_str(char *str)
{
	int s;

	for (s = 0; str[s] != '\0'; ++s)
	{
		_putchar((int)*str);
		++str;
	}
	return (s);
}

/**
 * print_digit - prints decimal or hexadecimal number(s)
 * @n: number to print
 * @base: base of n
 *
 * Return: digit or hexadecimal
 */
int print_digit(long n, int base)
{
	int count;
	char *symbols;

	count = 0;
	symbols = "0123456789abcdef";

	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (_putchar(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

/**
 * _printf - our printf function
 * @format: the input argument
 *
 * Return: a
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int a;

	va_start(ap, format);

	a = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			a += print_format(*(++format), ap);
		else
		{
			a += write(1, format, 1);
			++format;
		}
	}
	va_end(ap);
	return (a);
}
