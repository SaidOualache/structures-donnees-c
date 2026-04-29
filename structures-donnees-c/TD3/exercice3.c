#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node* deleteMin(Node *head) {
    if(!head) return NULL;

    Node *cur = head;
    Node *minPrev = NULL;
    int min = head->val;

    while(cur->next) {
        if(cur->next->val < min) {
            min = cur->next->val;
            minPrev = cur;
        }
        cur = cur->next;
    }

    if(!minPrev) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    } else {
        Node *tmp = minPrev->next;
        minPrev->next = tmp->next;
        free(tmp);
        return head;
    }
}