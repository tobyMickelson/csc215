#include <stdio.h>
#include "LINKLIST.H"
#define NULL 0

struct node *mknode(n) int n; {
    struct node* x;
    x = alloc(4);
    x->num = n;
    x->next = NULL;
    return x;
}


/* returns number of nodes in the list */
int lsize(head)
struct node* head;
{
    int count;
    count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* returns 1 if list is empty, 0 otherwise */
int isempty(head)
struct node* head;
{
    if (head == NULL) 
        return 1;
    return 0;
}

char* prnlist(list, list_str)
struct node* list;
char* list_str;
{
    struct node* p;
    char* ptr;
    char numbuf[10];
    int i, neg;

    ptr = list_str;
    p = list;
    *ptr++ = '[';

    while (p != NULL) {
        i = 0;
        neg = p->num < 0;
        if (neg) p->num = -p->num;

        do {
            numbuf[i++] = '0' + (p->num % 10);
            p->num /= 10;
        } while (p->num > 0);

        if (neg) numbuf[i++] = '-';
        while (--i >= 0) *ptr++ = numbuf[i];

        if (p->next != NULL) {
            *ptr++ = ' '; *ptr++ = '-'; *ptr++ = '>';
            *ptr++ = ' ';
        }
        p = p->next;
    }

    *ptr++ = ']';
    *ptr = '\0';
    return list_str;
}


void dellst(list) struct node* list; {
    struct node* Next; struct node* current;
    current = list;
    while(current != NULL){
        Next = current->next;
        free(current);
        current = Next; 
    }
    list = NULL;
}

void insert(list, data, position)
	struct node* list;
	int data;
	int position;
{
	struct node* curr_node;
	struct node* prev_node;
	curr_node = list;
	while (position > 0) {
		if (curr_node == NULL) {
			return;
		}
		prev_node = curr_node;
		curr_node = curr_node->next;
		position--;
	}
	struct node* new_node;
	new_node = mknode(data);
	new_node->next = curr_node;
	prev_node->next = new_node;
	return;
}
