#include "my_printf.h"

int	my_putchar(const int c)
{
	write(1 , &c, 1);
	return (1);
}