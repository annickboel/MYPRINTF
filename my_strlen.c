#include "my_strlen.h"
int my_strlen(char const *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;
	return (count);
}