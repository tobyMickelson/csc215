#include "stdio.h"


int main(argc, argv)
int argc;
char **argv;
{
  int a;
  char b;
  short c;
  unsigned d;
  printf("int: %d\n",      (sizeof a) * 8);
  printf("char: %d\n",     (sizeof b) * 8);
  printf("short: %d\n",    (sizeof c) * 8);
  printf("unsigned: %d\n",   (sizeof d) * 8);
  int x, y;
  x = -3;
  y = 10;
  printf("signed division (ll): %d / %d = %d\n", -3, 10, -3 / 10);
  printf("signed division (vl): %d / %d = %d\n",  x, 10,  x / 10);
  printf("signed division (lv): %d / %d = %d\n", -3,  y, -3 /  y);
  printf("signed division (vv): %d / %d = %d",  x,  y,  x /  y);
}
