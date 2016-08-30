#ifndef __LIST_H
#define __LIST_H

#include "common.h"

typedef struct node{
    void *data;
    struct node *next;
}node;

typedef struct list{
    int length;
    int element_size;
    node *head;
    node *tail;
    free_function free_func;
}list;

void list_new(list *list, int element_size, free_function free_func);
void list_destroy(list *list);

void list_prepend(list *list, void *element);
void list_append(list *list, void *element);
int list_size(list *list);

void list_head(list *list, void *element);
void list_tail(list *list, void *element);

void list_pop_head(list *list, void *element);
void list_pop_tail(list *list, void *element);

#endif