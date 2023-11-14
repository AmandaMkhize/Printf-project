#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
	* custom_print_char - Custom function to print a character
	* @args: Arguments list
	* Return: Number of characters printed
	*/
int custom_print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
	* custom_print_string - Custom function to print a string
	* @args: Arguments list
	* Return: Number of characters printed
	*/
int custom_print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	while (*str)
	{
	len += write(1, str, 1);
	str++;
	}

	return (len);
}

/**
	* custom_print_percent - Custom function to print a percent sign
	* @args: Arguments list
	* Return: Always returns 1
	*/
int custom_print_percent(va_list args)
{
	(void)args;

	return (write(1, "%", 1));
}

/**
	* my_printf - Custom printf function
	* @format: Format string containing directives
	* Return: Number of characters printed (excluding null byte)
	*/
int my_printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int (*print_func)(va_list) = NULL;

	va_start(args, format);

	while (*format)
	{
	if (*format != '%')
	{
	count += write(1, format, 1);
	}
	else
	{
	format++;

	switch (*format)
	{
	case 'c':
	print_func = custom_print_char;
	break;
	case 's':
	print_func = custom_print_string;
	break;
	case '%':
	print_func = custom_print_percent;
	break;
	default:
	break;
	}

	if (print_func)
	{
	count += print_func(args);
	}
	}

	format++;
	}

	va_end(args);
	return (count);
}
