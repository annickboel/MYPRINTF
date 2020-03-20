
#include "my_printf.h"

int my_putnbr_base(const int nb, const int base) {
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

        value = (nb - mod) / base;
        my_putnbr_base(value, base);
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


int my_put_unsigned_nbr(unsigned int nb) {
  int written = 0;
  unsigned int  value;

  if (nb >= 10) {
      value = nb % 10;
      nb = nb / 10;
      my_put_unsigned_nbr(nb);
      my_putchar(value + 48);
      written++;
    }
  else {
    my_putchar(nb + 48);
    written++;
  }
  return (written);
}


