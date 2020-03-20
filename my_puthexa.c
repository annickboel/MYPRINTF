#include "my_printf.h"

int my_puthexa(const int nb, const int flag) {
  int written = 0;
  int value = nb;
  int mod;
  int digit;
  char * lower_digits = "0123456789abcdef";
  char * upper_digits = "0123456789ABCDEF";
  char * digits;

  digits = (flag) ? upper_digits : lower_digits;

  if (value < 0) {
      my_putchar('-');
      written ++;
      value = value * (-1);
   }
   if (value >= 0)  {
      if (value >= 16) {
        mod = (nb % 16);
        value = (nb - mod) / 16;
        my_puthexa(value, flag);
        digit = mod;
        if (digit <10) {
          my_putchar(48 + digit);
        }
        else {
          my_putchar(digits[digit]);
        }
        written ++;
      }
      else {
          digit = value % 16;
          if (digit <10) {
            my_putchar(48 + digit);
          }
          else {
            my_putchar(digits[digit]);
          }
          written ++;
      }
  }
  return (written);
}