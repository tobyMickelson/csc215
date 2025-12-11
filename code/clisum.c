#include <stdio.h>


main(argc, argv)
int argc;
char** argv;
{
  int arg;
  int sum;
  int tempsum;
  int c;
  int dontrun;

  dontrun = 0;
  for (arg = 1; arg < argc; arg++) {
    tempsum = 0;
    
    for (c = 0; argv[arg][c] != 0; c++) {
      if (argv[arg][c] < '0' || argv[arg][c] > '9') {
        dontrun = 1;
        printf("OOPS! %s is not a number\n", argv[arg]);
        break;
      }
      tempsum = (tempsum * 10) + (argv[arg][c] - '0');
    }
    
    sum += tempsum;
  }

  if (!dontrun)
    printf("Sum is %d", sum);
}
