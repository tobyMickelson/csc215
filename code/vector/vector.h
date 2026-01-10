#ifndef VECTOR_H
#define VECTOR_H

struct _vector {
  int size;
  int capacity;
  char* data;
};
#define vector struct _vector

void v_init();
void v_resize();
void v_push_back();
char v_pop_back();
void v_deinit();

#endif
