#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* clear(Node *head) {
    Node *tmp;
    while(head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return NULL;
}