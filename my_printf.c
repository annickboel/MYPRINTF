#include "my_printf.h"
#include <stdio.h> 

int get_printer(const char specifier) {
	int i;
	int index=-1;
	for (i=0;i<my_strlen(SPECIFIERS); i++) {
		if (specifier == SPECIFIERS[i]) {
			index = i;
			break;
		}
	}
	return (index);
}

int	print_arg(const char flag, va_list ap)
{
	int	written = 0;
	arg_printer printers[9];

	printers[0].pf = &print_s_arg;
	printers[1].pf = &print_i_arg;
	printers[2].pf = &print_d_arg;
	printers[3].pf = &print_c_arg;
	printers[4].pf = &print_o_arg;
	printers[5].pf = &print_u_arg;
	printers[6].pf = &print_x_arg;
	printers[7].pf = &print_X_arg;
	printers[8].pf = &print_Z_arg;
	//int index=get_printer(flag);
	//written += printers[index].pf(ap);

	switch (flag) {
		case 's':
			written += printers[0].pf(ap);
			break;
		case 'i':
			written += printers[1].pf(ap);
			break;
		case 'd':
			written += printers[2].pf(ap);
			break;
		case 'c':
			written += printers[3].pf(ap);
			break;
		case 'o':
			written += printers[4].pf(ap);
			break;
		case 'u':
			written += printers[5].pf(ap);
			break;
		case 'x':
			written += printers[6].pf(ap);
			break;
		case 'X':
			written += printers[7].pf(ap);
			break;
		case '%':
			written += printers[8].pf(ap);
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
