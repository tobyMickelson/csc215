#include "stdio.h"

#define MAX_LINE_LEN 255
#define BUFFER_LEN ( MAX_LINE_LEN + 1 )

strlen(str)
char *str;
{
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

main(argc, argv)
int argc;
char **argv;
{ 
  FILE *fp;
  short line_end_val;
  char at_eof;
  char buffer[BUFFER_LEN];

  if (argc == 1) {
    printf(
        "usage: chrnums <file> [nNcCiI]\noptions:\n    n|N: no include line ending (default)\n    c|C: c-style (single character) line ending\n    i|I: include line ending"
    );
    return;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("error opening file");
    return;
  }

  line_end_val = -1;
  if (argc == 3) {
    switch (argv[2][0]) {
      case 'n':  /* no include line ending */
      case 'N':
        line_end_val = -1;
        break;
      case 'c':  /* c-style line ending */
      case 'C':
        line_end_val = 0;
        break;
      case 'i':  /* include line ending */
      case 'I':
        line_end_val = 1;
        break;
      default:
        printf("unknown option");
        fclose(fp);
        return;
    }
  }

  at_eof = FALSE;
  while (!at_eof) {
    at_eof = !fgets(buffer, MAX_LINE_LEN, fp);
    printf(
        "%d:\t%s",
        buffer[strlen(buffer) - 1] == '\n' ?
            strlen(buffer) + line_end_val : strlen(buffer),
        buffer
    );
  }

  fclose(fp);
}
