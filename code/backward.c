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

reverse(str)
char *str;
{
  int i;
  int len;
  char temp;
  len = strlen(str);
  for (i = 0; i < len / 2; i++) {
    temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

main(argc, argv)
int argc;
char **argv;
{
  FILE *fp;
  char at_eof;
  char newline;
  char buffer[BUFFER_LEN];

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("error opening file");
    return;
  }

  at_eof = FALSE;
  while (!at_eof) {
    at_eof = !fgets(buffer, MAX_LINE_LEN, fp);
    if (buffer[strlen(buffer) - 1] == '\n') {
      buffer[strlen(buffer) - 1] = 0;
      newline = TRUE;
    } else {
      newline = FALSE;
    }
    
    reverse(buffer);
    printf("%s%s", buffer, newline ? "\n" : "");
  }
}
