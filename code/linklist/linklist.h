#define linklist struct _node
struct _node {
  int num;
  linklist *next;
};

linklist *mknode(int data);
linklist *mkempty();
char *prnlist(linklist *list, char *list_str);
int lsize(linklist *list);
int isempty(linklist *list);
linklist *getnode(linklist *list, int index);
int getnum(linklist *list, int index);
void insert(linklist *list, int index, int data);
int remove(linklist *list, int index);
void dellst(linklist *list);
