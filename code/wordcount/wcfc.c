#include "stdio.h"

char iswsp(c)
char c;
{
  switch (c) {
  case 9:   /* ht */
  case 10:  /* lf */
  case 11:  /* vt */
  case 12:  /* ff */
  case 13:  /* cr */
  case ' ':
    return TRUE;
  default:
    return FALSE;
  }
}

int wcfile(f)
char *f;
{
  FILE *fp;
  char inword;  /* poor man's bool */
  int words;
  int c;
  
  fp = fopen(f, "r");
  if (fp == NULL) {
    printf("error opening file");
    return 0;
  }

  inword = FALSE;
  words = 0;

  while (TRUE) {
    c = fgetc(fp);
    if (c == EOF) break;

    if (iswsp(c)) {
      inword = FALSE;
    } else {
      if (!inword) {
        words++;
        inword = TRUE;
      }
    }
  }

  fclose(fp);

  return words;
}

main(argc, argv)
int argc;
char **argv;
{
  int words;
  
  if (argc != 2) {
    printf("wcfc: word count file, c ver.\nusage: wcfc <file>");
    return 0;
  }
  
  words = wcfile(argv[1]);
  printf("%d", words);
}
