#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
    char *key;
    int value;
    struct listnode *next;
} listnode;

listnode *list_createnode(char *key, int value);
listnode *list_addfront(listnode *list, char *key, int value);
listnode *list_lookup(listnode *list, char *key);
listnode *list_delete(listnode *list, char *key);
void *list_sort(listnode *head);
void list_print(listnode *head);
void list_write_file(FILE *in, listnode *head);
void list_reverse(listnode **head);
void list_sort_descending(listnode **head);