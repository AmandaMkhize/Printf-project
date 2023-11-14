#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int custom_print_char(va_list args);
int custom_print_string(va_list args);
int custom_print_percent(va_list args);
int my_printf(const char *format, ...);
int _printf(const char *format, ...);

#endif
