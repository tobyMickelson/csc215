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
  printf("unsigned: %d",   (sizeof d) * 8);
}
