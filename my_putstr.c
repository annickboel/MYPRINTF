#include "my_putstr.h"

int	my_putstr(const char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (i);
}


