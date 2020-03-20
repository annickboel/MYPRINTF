#ifndef MY_PRINT_ARGS_H
#define MY_PRINT_ARGS_H
#include <stdarg.h>
#include "my_putstr.h"
#include "my_putnbr.h"
#include "my_puthexa.h"
#include "my_print_args.h"
#include "my_strlen.h"

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


#endif