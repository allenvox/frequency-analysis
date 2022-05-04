#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

listnode *list_createnode(char *key, int value) {
    listnode *p;
    p = malloc(sizeof(*p));
    if (p != NULL) {
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    return p;
}

listnode *list_addfront(listnode *list, char *key, int value) {
    listnode *newnode;
    newnode = list_createnode(key, value);
    if (newnode != NULL) {
        newnode->next = list;
        return newnode;
    }
    return list;
}

listnode *list_lookup(listnode *list, char *key) {
    for ( ; list != NULL; list = list->next) {
        if (strcmp(list->key, key) == 0) {
            return list;
        }
    }
    return NULL; // not found
}

listnode *list_delete(listnode *list, char *key) {
    listnode *p, *prev = NULL;
    for (p = list; p != NULL; p = p->next) {
        if (strcmp(p->key, key) == 0) {
            if (prev == NULL) {
                list = p->next; // deleting head
            } else {
                prev->next = p->next; // left exists
            }
            free(p);
            return list; // head pointer
        }
        prev = p; // remembering previous
    }
    return NULL; // not found
}

void *list_sort(listnode *head) {
    listnode *node = NULL, *temp = NULL;
    int tempValue;
    char* tempKey;
    node = head;
    while (node != NULL) {
        temp = node;
        while(temp->next != NULL) {
            if(temp->value > temp->next->value) {
                tempValue = temp->value;
                temp->value = temp->next->value;
                temp->next->value = tempValue;

                tempKey = temp->key;
                temp->key = temp->next->key;
                temp->next->key = tempKey;
            }
            temp = temp->next;
        }
        node = node->next;
    }
    return NULL;
}

void list_print(listnode *head) {
    listnode *current = head;  
    while(current != NULL) {
        printf("%s - %d\n", current->key, current->value);  
        current = current->next;
    }
}

void list_write_file(FILE *in, listnode *head) {
    listnode *current = head;  
    while(current != NULL) {
        if(current->value > 1) {
            fprintf(in, "%s - %d\n", current->key, current->value);
        } 
        current = current->next;
    }
}

void list_reverse(listnode **head) {
    listnode *prev = NULL, *current = *head, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void list_sort_descending(listnode **head) {
    list_sort(*head);
    list_reverse(head);
}

void list_fill_with_words(listnode **head, char **words, int size) {
    for(int i = 1; i < size; i++) {
        listnode *node = list_lookup(*head, words[i]);
        if(node != NULL) {
            node->value++;
        } else {
            *head = list_addfront(*head, words[i], 1);
        }
    }
}