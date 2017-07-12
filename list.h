#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#ifndef BIG_STRING
#define STRING_SIZE 10
#else
#define STRING_SIZE 5
#endif

typedef enum {ERROR=-1, OK=0} status;

/// node - The stack structure
typedef struct _node {
    struct _node *next;
    char *element;
} node;

/// push - Push an element
///
/// @param head - The head of the stack
/// @param element - The element to push
/// @return curr - The current stack
node *push(node *head, char *element) {
    if (isEmpty(head)) {
        node *first;
        first = calloc(1, sizeof(struct _node));
        first->element = calloc(STRING_SIZE, sizeof(char));
        strcpy(first->element, element);
        first->next = NULL;
#ifdef DEBUG
        printf("Element [%s] added as head\n", element);
#endif
        return first;
    }
    node *curr;
    curr = head;
    while ((curr->next != NULL) && (curr != NULL)) {
        curr = curr->next;
    }
    node *tmp;
    tmp = calloc(1, sizeof(struct _node));
    tmp->element = calloc(STRING_SIZE,sizeof(char));
    strncpy(tmp->element, element, STRING_SIZE);
    tmp->next = NULL;
    curr->next = tmp;
#ifdef DEBUG
    printf("Pushing element [%s]\n", element);
#endif
    return curr;
}

/// pop - Pop an element
///
/// @param head - The head of the stack
/// @return ret - The element
char *pop(node **head) {
    if (isEmpty(head)) {
        return NULL;
    }
    node *curr;
    curr = *head;
    char *ret = calloc(STRING_SIZE, sizeof(char));
#ifdef DEBUG
    printf("Popping element [%s] \n", curr->element);
#endif
    strncpy(ret, curr->element, STRING_SIZE);
    *head = (*head)->next;
    free(curr->element);
    free(curr);
    return ret;
}

/// printList - Print the stack
///
/// @return status - The status
int printList(node *head) {
    if (isEmpty(head)) {
        return ERROR;
    }
    node *curr = head;
    while (curr->next != NULL || curr == NULL) {
        printf("[%s]\t", curr->element);
        curr = curr->next;
    }
    printf("[%s]\n", curr->element);
    return OK;
}

/// freeList - Free the list
///
/// @param head - The head of the stack
void freeList(node *head) {
    node *curr = head;
    node *tmp = NULL;
    while (curr != NULL) {
        tmp = curr;
#ifdef DEBUG
        printf("Freeing element [%s] \n", curr->element);
#endif
        curr = curr->next;
        free(tmp->element);
        free(tmp);
    }
}

/// isEmpty - Check if list is empty
///
/// @param head - The head of the stack
int isEmpty(node* head) {
    return (head == NULL);
}


/// peak - Peak the top of the stack
///
/// @param head - The head of the stack
/// @return ret - The element at the head
char* peak(node* head) {
    if (isEmpty(head)) {
        return NULL;
    }
    char *ret = calloc(STRING_SIZE, sizeof(char));
    ret = head->element;
    return ret;
}