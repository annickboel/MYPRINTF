#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include "my_putstr.h"
#include "my_putnbr.h"
#include "my_puthexa.h"
#include "my_print_args.h"
#include "my_strlen.h"


int my_printf(const char *, ...);
int get_printer(const char);
#endif