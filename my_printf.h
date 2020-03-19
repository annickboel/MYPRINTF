#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include "my_putstr.h"
#include "my_putnbr.h"
#include "my_strlen.h"


struct f_print
{
    int(*ptr_fct)(va_list ap);
    char flag;
};



int my_printf(const char *, ...);
int	print_arg(const char, va_list);
int print_s_arg(va_list ap);
int print_c_arg(va_list ap);
int print_d_arg(va_list ap);
int print_i_arg(va_list ap);
#endif