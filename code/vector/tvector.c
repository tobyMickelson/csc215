#include "stdio.h"
#include "vector.h"


int main(argc, argv)
int argc;
char **argv;
{
  int i;
  vector vec;
  printf("\t\tHello, World!\n");
  v_init(&vec, 1);
  printf("\t\tsize: %d\tmax_size: %d\n", vec.size, vec.max_size);
  
  for (i = 1; i <= 10; i++) {
    v_push_back(&vec, i);
    printf("added %d to vec\tsize: %d\tmax_size: %d\n", i, vec.size, vec.max_size);
  }
  for (i = 1; i <= 10; i++) {
    printf("got %d from vec\tsize: %d\tmax_size: %d\n", v_pop_back(&vec), vec.size, vec.max_size);
  }
  
  v_deinit(&vec);
  printf("\t\tsize: %d\tmax_size: %d", vec.size, vec.max_size);

  return 0;
}
