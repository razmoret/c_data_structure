#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

void list_new(list *list, int element_size, free_function free_func)
{
    assert(element_size > 0);
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    list->free_func = free_func;
}

void list_destroy(list *list)
{
    node *tmp_node;
    while(list->head != NULL){
        tmp_node = list->head;
        list->head = tmp_node->next;

        if(list->free_func){
            list->free_func(tmp_node->data);
        }else{
            free(tmp_node->data);
        }
        free(tmp_node);
    }
}

void list_prepend(list *list, void *element)
{
    node *tmp_node = (node *)malloc(sizeof(node));
    tmp_node->data = (void *)malloc(list->element_size);
    memcpy(tmp_node->data, element, list->element_size);

    tmp_node->next = list->head;
    list->head = tmp_node;

    if(!list->tail){
        list->tail = list->head;
    }

    list->length++;
}

void list_append(list *list, void *element)
{
    node *tmp_node = (node *)malloc(sizeof(node));
    tmp_node->data = (void *)malloc(list->element_size);
    memcpy(tmp_node->data, element, list->element_size);

    tmp_node->next = NULL;

    if(list->length == 0){
        list->head = tmp_node;
    }else{
        list->tail->next = tmp_node;
        list->tail = tmp_node;
    }

    list->length++;
}

int list_size(list *list)
{
    return list->length;
}

void list_head(list *list, void *element)
{
    assert(list->head != NULL);
    memcpy(element, list->head->data, list->element_size);
}

void list_tail(list *list, void *element)
{
    assert(list->tail != NULL);
    memcpy(element, list->tail->data, list->element_size);
}

void list_pop_head(list *list, void *element)
{
    assert(list->head != NULL);
    memcpy(element, list->head->data, list->element_size);

    node *tmp_node = list->head;

    if(list->head->next != NULL){
        list->head = list->head->next;
    }else{
        list->head = NULL;
    }

    if(list->free_func){
        list->free_func(tmp_node->data);
    }else{
        free(tmp_node->data);
    }
    free(tmp_node);

}

void list_pop_tail(list *list, void *element)
{
    assert(list->tail != NULL);
    memcpy(element, list->tail->data, list->element_size);

    node *tmp_node = list->tail;
    node *traverse = list->head;    
    if(list->head != list->tail){
        // not one node list
        while(traverse->next->next != NULL){
            traverse = traverse->next;
        }
        list->tail = traverse;
        traverse->next = NULL;
    }

    if(list->free_func){
        list->free_func(tmp_node->data);
    }else{
        free(tmp_node->data);
    }
    free(tmp_node);
}

int main(int argc, char *argv[])
{

	return 0;
}
