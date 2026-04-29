#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

int findMin(Node *r) {
    while(r->left) {
        r = r->left;
    }
    return r->val;
}