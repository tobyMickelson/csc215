struct _vector {
  int size;
  int max_size;
  char* data;
};
#define vector struct _vector

void v_init();
void v_realloc();
void v_push_back();
char v_pop_back();
void v_deinit();
