#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* addStart(Node *head, int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->next = head;
    return n;
}

int main() {
    Node *head = NULL;
    int i;

    for(i = 0; i < 100; i++) {
        head = addStart(head, rand() % 100);
    }

    return 0;
}