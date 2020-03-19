#include "my_printf.h"
#include <stdio.h> 


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
	my_putnbr(integer);
	return (written);
}

int print_i_arg(va_list ap) {
	int	written = 0;

	written = print_d_arg(ap);
	return (written);
}


int	print_arg(const char flag, va_list ap)
{
	int	written = 0;

	int (*pfs)(va_list);
	pfs = &print_s_arg;

	int (*pfc)(va_list);
	pfc = &print_c_arg;

	int (*pfi)(va_list);
	pfi = &print_i_arg;

	int (*pfd)(va_list);
	pfd = &print_d_arg;

	switch (flag) {
		case 's':
			written += (*pfs)(ap);
			break;
		case 'i':
			written += (*pfi)(ap);
			break;
		case 'd':
			written += (*pfd)(ap);
			break;
		case 'c':
			written += (*pfc)(ap);
			break;
	}
	return (written);
}

int my_printf(const char *s, ...)
{
	int len = my_strlen(s);
	int i = 0;
	int	written = 0;
	char flag;

	va_list ap;
	va_start(ap, s);

	for (i=0; i<len; i++) {
		if (s[i] == '%' && s[i + 1] != '\0') {
			flag = s[i + 1];
			print_arg(flag, ap);
			i++;
		}
		else {
			written += my_putchar(s[i]);
		}

	}
	va_end(ap);
	return (0);
}
