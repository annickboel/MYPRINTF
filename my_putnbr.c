
#include "my_putnbr.h"
#include <stdio.h>

int my_putnbr(const int nb) {
  int written = 0;
  int value = nb;
  int mod;

  if (value < 0) {
      my_putchar('-');
      written ++;
      value = value * (-1);
   }
   if (value >= 0)  {
     	if (value >= 10) {
     		mod = (nb % 10);
    		value = (nb - mod) / 10;
			my_putnbr(value);
			my_putchar(48 + mod);
			written ++;
    	}
	    else {
	        my_putchar(48 + (value % 10));
	        written ++;
	    }
	}
	return (written);
}


int my_putnbr_base(const int nb, const int base) {
  //printf("my_putnbr_base %d %d\n", nb, base);
  int written = 0;
  int value = nb;
  int mod;

  if (value < 0) {
      my_putchar('-');
      written ++;
      value = value * (-1);
   }
   if (value >= 0)  {
      if (value >= base) {
        mod = (nb % base);
        //printf("mod %d\n", mod);
        value = (nb - mod) / base;
        //printf("value %d\n", value);
        my_putnbr(value);
        my_putchar(48 + mod);
        written ++;
      }
      else {
          my_putchar(48 + (value % base));
          written ++;
      }
  }
  return (written);
}

