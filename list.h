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

typedef struct _node {
    struct _node *next;
    char *element;
} node;

node *push(node *head, char *element) {
    if (head == NULL) {
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

char *pop(node **head) {
    if (*head == NULL) {
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

int printList(node *head) {
    if (head == NULL) {
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