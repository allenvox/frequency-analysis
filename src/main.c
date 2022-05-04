#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#include "input.h"

int main(int argc, char **argv)
{
    if(checkArgs(argc, argv) == -1) {
        return -1;
    }
    int wordCount = 0;
    char **words = getInput(argv[1], &wordCount);

    listnode *head = list_addfront(NULL, words[0], 1);
    for(int i = 1; i < wordCount; i++) {
        listnode *node = list_lookup(head, words[i]);
        if(node != NULL) {
            node->value++;
        } else {
            head = list_addfront(head, words[i], 1);
        }
    }
    free(words);

    list_sort_descending(&head);
    FILE *in = fopen(argv[2], "w+");
    list_write_file(in, head);
    fclose(in);
    return 0;
}