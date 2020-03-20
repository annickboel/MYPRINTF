#include "my_printf.h"

int print_s_arg(va_list ap) {

	int	written = 0;
	const char * str;

	str = (const char *) va_arg(ap, const char *);
	my_putstr(str);
	return (written);
}

int print_c_arg(va_list ap) {

	int	written = 0;
	char c;

	c = va_arg(ap, int);
	my_putchar(c);
	return (written);
}

int print_d_arg(va_list ap) {

	int	written = 0;
	int integer;

	integer = (int) va_arg(ap, int);
	my_putnbr_base(integer, 10);
	return (written);
}

int print_i_arg(va_list ap) {

	int	written = 0;

	written = print_d_arg(ap);
	return (written);
}

int print_o_arg(va_list ap) {

	int	written = 0;
	int integer;

	integer = (int) va_arg(ap, int);
	my_putnbr_base(integer, 8);
	return (written);
}

int print_u_arg(va_list ap) {
	
	int	written = 0;
	unsigned int nbr;

	nbr = (unsigned int) va_arg(ap, unsigned int);
	my_put_unsigned_nbr(nbr);
	return (written);
}

int print_x_arg(va_list ap) {
	
	int	written = 0;
	int integer;

	integer = (int) va_arg(ap, int);
	my_puthexa(integer, 0);
	return (written);
}

int print_X_arg(va_list ap) {
	
	int	written = 0;
	int integer;

	integer = (int) va_arg(ap, int);
	my_puthexa(integer, 1);
	return (written);
}

int print_Z_arg(va_list ap) {

	int	written = 0;
	ap+=0;
	written = my_putchar('%');
	return (written);
}