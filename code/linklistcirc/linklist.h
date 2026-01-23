#ifndef LINKLIST_H
#define LINKLIST_H

struct node {
    int num;
    struct node* next;
};

struct node* mknode(struct node* head, int n);
char* prnlist(struct node* list, char* list_str);
int lsize(struct node* list);
int isempty(struct node* list);
void dellst(struct node* list);
void insert(struct node* list, int data, int position);

#endif
