#ifndef STRING_H
#define STRING_H

strlen(str)
char *str;
{
  int i;
  /* for (i = 0; str[i] != '\0'; i++); */
  for (i = 0; str[i]; i++);
  return i;
}

char *reverse(str)
char *str;
{
  int i;
  int len;
  char temp;
  len = strlen(str);
  for (i = 0; i < len / 2; i++) {
    temp = *(str + i);
    *(str + i) = *(str + len - 1 - i);
    *(str + len - 1 - i) = temp;
  }

  return str;
}

strcpy(a, b)
char *a;
char *b;
{
  /* while (*a != '\0') *b++ = *a++; */
  while (*a) *b++ = *a++;
  *b = '\0';
}

char *itoa(val)
int val;
{
  char *str;
  char *ptr;
  str = alloc(6);
  ptr = str;
  
  while (val) {
    *ptr++ = (val % 10) + '0';
    val /= 10;
  }

  return reverse(str);
}

atoi(str)
char *str;
{
  int val;
  if (*str < '0' || '9' < *str) return -1;
  val = *str++ - '0';

  while (*str >= '0' && '9' >= *str)
    val = (val * 10) + (*str++ - '0');

  return val;
}

#endif
