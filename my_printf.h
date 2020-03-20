#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
/*#include "my_putstr.h"
#include "my_putnbr.h"
#include "my_puthexa.h"
#include "my_strlen.h"*/


typedef struct f_print
{
    int(*pf)(va_list ap);
} arg_printer;

#define SPECIFIERS "sidcouxXZ"

int print_s_arg(va_list ap);
int print_c_arg(va_list ap);
int print_d_arg(va_list ap);
int print_i_arg(va_list ap);
int print_o_arg(va_list ap);
int print_u_arg(va_list ap);
int print_x_arg(va_list ap);
int print_X_arg(va_list ap);
int print_Z_arg(va_list ap);

int my_printf(const char *, ...);
int get_printer(const char);

int	my_putchar(int c);
int my_puthexa(const int nb, const int flag);
int my_putnbr(const int nb);
int my_putnbr_base(const int nb, const int base);
int	my_putstr(const char* s);
int my_strlen(char const *str);

#endif