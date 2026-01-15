#include "stdio.h"

#include "bigint.h"

void set_bigint(num, numstr)
bigint *num;
char *numstr;
{
  char last_pos, i;
  num->negative = (numstr[0] == '-');
  num->numdigits = strlen(numstr) - num->negative;
  num->digits = alloc(num->numdigits);
  last_pos = num->numdigits + (num->negative ? 0 : -1);

  for (i = 0; i < num->numdigits; i++) {
    num->digits[i] = numstr[last_pos - i];
    /* printf("numstr[%d] is %c\n", last_pos-i, numstr[last_pos-i]); */
  }
}
/* order of "1234" appears to be ['4', '3', '2', '1'] with no null term. */

char *get_bigint(num)
bigint *num;
{
  char *numstr;
  char start_pos, i;
  numstr = alloc(num->numdigits + (num->negative ? 2 : 1));
  start_pos = num->negative;
  if (start_pos == 1)
    numstr[0] = '-';
  for (i = 0; i < num->numdigits; i++) {
    numstr[i + start_pos] = num->digits[num->numdigits - (i + 1)];
    /* printf("numstr[%d] is %c\n", i, numstr[i+start_pos]); */
  }
  numstr[num->numdigits + start_pos] = '\0';
  return numstr;
}

void add_bigints(a, b, out)
bigint *a, *b, *out;
{
  if (a->negative != b->negative) {
    b->negative = !b->negative;
    sub_bigints(a, b, out);
    b->negative = !b->negative;
    return;
  }
  
  char temp;
  char adone, bdone;
  int i, carry;

  out->numdigits = max(a->numdigits, b->numdigits) + 1;
  out->negative = a->negative;
  out->digits = alloc(out->numdigits);

  i = 0;
  adone = 0; bdone = 0;
  carry = 0;
  do {
    temp = (adone ? 0 : a->digits[i] - '0') + (bdone ? 0 : b->digits[i] - '0') + carry;
    carry = temp / 10;
    temp %= 10;

    temp += '0';
    out->digits[i++] = temp;
    
    if (i >= a->numdigits) adone = 1;
    if (i >= b->numdigits) bdone = 1;
  } while (!adone || !bdone);

  if (carry) out->digits[i++] = carry + '0';

  out->numdigits = i;
}

void sub_bigints(a, b, out)
bigint *a, *b, *out;
{
  if (a->negative != b->negative) {
    b->negative = !b->negative;
    sub_bigints(a, b, out);
    b->negative = !b->negative;
    return;
  }
  
  char temp;
  char adone, bdone;
  int i, carry;

  out->numdigits = max(a->numdigits, b->numdigits) + 1;
  out->negative = a->negative;
  out->digits = alloc(out->numdigits);

  i = 0;
  adone = 0; bdone = 0;
  carry = 0;
  do {
    temp = (adone ? 0 : a->digits[i] - '0') - (bdone ? 0 : b->digits[i] - '0') + carry;
    carry = temp / 10;
    temp %= 10;

    temp += '0';
    out->digits[i++] = temp;
    
    if (i >= a->numdigits) adone = 1;
    if (i >= b->numdigits) bdone = 1;
  } while (!adone || !bdone);

  if (carry) out->digits[i++] = carry + '0';

  out->numdigits = i;
}
