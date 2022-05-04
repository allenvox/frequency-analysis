#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "input.h"

int main(int argc, char **argv)
{
    if(checkArgs(argc, argv) == -1) {
        return -1;
    }
    int wordCount = 0;
    char **words = getInput(argv[1], &wordCount);
    listnode *head = list_createnode(words[0], 1);
    list_fill_with_words(&head, words, wordCount);
    free(words);
    list_sort_descending(&head);
    FILE *in = fopen(argv[2], "w+");
    list_write_file(in, head);
    fclose(in);
    return 0;
}