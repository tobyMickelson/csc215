#include <stdio.h>
#include <linklist.h>

linklist *mknode(data)
int data;
{
  linklist *list;
  list = alloc(4);
  list->num = data;
  list->next = NULL;
  return list;
}

linklist *mkempty()
{
  return NULL;
}

char *prnlist(list, list_str)
linklist *list;
char *list_str;
{
  if (isempty(list)) {
    list_str = alloc(1);
    *list_str = '\0';
    return list_str;
  }
  
  list_str = alloc(lsize(list) * 8 + 8);
  while (list->next) {
    sprintf(list_str + strlen(list_str), "%d->", list->num);
    list = list->next;
  }
  list_str[strlen(list_str) - 1] = '\0';
  return list_str;
}

int lsize(list)
linklist *list;
{
  if (list == NULL) return 0;
  
  int size;
  size = 1;
  while (list->next) {
    size++;
    list = list->next;
  }
  return size;
}

int isempty(list)
linklist *list;
{
  if (list == NULL) return 1;
  return 0;
}

linklist *getnode(list, index)
linklist *list;
int index;
{
  int i;
  for (i = 0; i < index; i++)
    list = list->next;
  return list;
}

int getnum(list, index)
linklist *list;
int index;
{
  return getnode(list, index)->num;
}

void insert(list, index, data)
linklist *list;
int index, data;
{
  linklist *new;
  new = alloc(4);
  new->num = data;

  if (index > 0)
    getnode(list, index - 1)->next = new;

  if (index < lsize(list))
    new->next = getnode(list, index);
  else
    new->next = NULL;

  return;
}

int remove(list, index)
linklist *list;
int index;
{
  
}

void dellst(list)
linklist *list;
{
  if (!list) return;
  
  linklist *temp;
  do {
    temp = list;
    free(temp);
    list = list->next;
  } while (list);

  list = NULL;
}
