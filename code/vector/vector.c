#include "stdio.h"
#include "vector.h"


void v_init(v, size_)
vector *v;
int size_;
{
  v->size = 0;
  v->capacity = size_;
  v->data = alloc(size_);
}

void v_resize(v, size_)
vector *v;
int size_;
{
  char *temp;
  temp = alloc(v->size);
  movmem(v->data, temp, v->size);
  free(v->data);
  v->capacity = size_;
  v->data = alloc(size_);
  movmem(temp, v->data, v->size);
  free(temp);
}

void v_push_back(v, val)
vector *v;
char val;
{
  if (v->size >= v->capacity) v_resize(v, v->capacity * 2);
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
  v->capacity = 0;
  v->data = 0;
}
