#include "list.h"
#ifndef MAX_EL
#define MAX_EL 6
#endif


int main() {
    char first_element[] = "String0";
    node *head;
    head = push(NULL, first_element);
    printList(head);
    char text[] = "String01";
    for (uint8_t i = 1; i < MAX_EL - 1 ; i++) {
        text[6] = (char) ((i / 10) + '0');
        text[7] = (char) ((i % 10) + '0');
        push(head, text);
        printList(head);
    }
#ifdef DEBUG
    printf("\nStarts with pop(ing)\n\n");
#endif
    char *n;
    n = calloc(STRING_SIZE, sizeof(char));
    for (uint8_t i = 1; i < MAX_EL-1; i++) {
        strncpy(n, pop(&head),1);
        printList(head);
        printf("Peak: %s\n", peak(head));
    }
#ifdef DEBUG
    printf("\nStarts freeing \n\n");
#endif
    free(n);
    freeList(head);
    return OK;
}