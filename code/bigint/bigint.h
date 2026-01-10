#ifndef BIGINT_H
#define BIGINT_H

struct _bigint {
  char negative;
  char numdigits;
  char *digits;
};
#define bigint struct _bigint

void set_bigint();
char *get_bigint();
void add_bigints();

#endif
