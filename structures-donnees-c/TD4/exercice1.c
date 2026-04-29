#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

Node* insert(Node *r, int x) {
    if(!r) {
        Node *n = (Node*)malloc(sizeof(Node));
        n->val = x;
        n->left = n->right = NULL;
        return n;
    }
    if(x <= r->val) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}

Node* find(Node *r, int x) {
    if(!r) return NULL;
    if(r->val == x) return r;
    if(x < r->val) return find(r->left, x);
    return find(r->right, x);
}

void count(Node *r, int x, int *c) {
    if(!r) return;
    count(r->left, x, c);
    if(r->val == x) (*c)++;
    count(r->right, x, c);
}

void print(Node *r) {
    if(!r) return;
    print(r->left);
    printf("%d ", r->val);
    print(r->right);
}

typedef struct list {
    int val;
    struct list *next;
} List;

List* addEnd(List *l, int v) {
    List *n = (List*)malloc(sizeof(List));
    n->val = v;
    n->next = NULL;
    if(!l) return n;
    List *cur = l;
    while(cur->next) cur = cur->next;
    cur->next = n;
    return l;
}

void treeToList(Node *r, List **l) {
    if(!r) return;
    treeToList(r->left, l);
    *l = addEnd(*l, r->val);
    treeToList(r->right, l);
}

Node* listToTree(List *l) {
    Node *r = NULL;
    while(l) {
        r = insert(r, l->val);
        l = l->next;
    }
    return r;
}

List* sortList(List *l) {
    Node *r = listToTree(l);
    List *res = NULL;
    treeToList(r, &res);
    return res;
}