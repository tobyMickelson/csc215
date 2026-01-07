#include "stdio.h"
#include "vector.h"


void v_init(v, size_)
vector *v;
int size_;
{
  v->size = 0;
  v->max_size = size_;
  v->data = alloc(size_);
}

void v_realloc(v, size_)
vector *v;
int size_;
{
  char *temp;
  temp = alloc(v->size);
  movmem(v->data, temp, v->size);
  free(v->data);
  v->max_size = size_;
  v->data = alloc(size_);
  movmem(temp, v->data, v->size);
  free(temp);
}

void v_push_back(v, val)
vector *v;
char val;
{
  if (v->size >= v->max_size) v_realloc(v, v->max_size * 2);
  v->data[v->size++] = val;
}

char v_pop_back(v)
vector *v;
{
  return v->data[--(v->size)];
}

void v_deinit(v)
struct _vector *v;
{
  free(v->data);
  v->size = 0;
  v->max_size = 0;
  v->data = 0;
}
