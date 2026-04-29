#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

int isBST(Node *r, int min, int max) {
    if(!r) return 1;
    if(r->val < min || r->val > max) return 0;
    return isBST(r->left, min, r->val) && isBST(r->right, r->val, max);
}