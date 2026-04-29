#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

int find(Node *head, int x) {
    while(head) {
        if(head->val == x) return 1;
        head = head->next;
    }
    return 0;
}