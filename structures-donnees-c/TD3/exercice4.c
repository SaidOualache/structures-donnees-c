#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* addEnd(Node *head, int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->next = NULL;

    if(!head) return n;

    Node *cur = head;
    while(cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node* merge(Node *a, Node *b) {
    Node *res = NULL;

    while(a && b) {
        res = addEnd(res, a->val);
        res = addEnd(res, b->val);
        a = a->next;
        b = b->next;
    }

    while(a) {
        res = addEnd(res, a->val);
        a = a->next;
    }

    while(b) {
        res = addEnd(res, b->val);
        b = b->next;
    }

    return res;
}