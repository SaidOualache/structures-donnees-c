#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int val;
    struct stack *next;
} Stack;

Stack* push(Stack *s, int v) {
    Stack *n = (Stack*)malloc(sizeof(Stack));
    n->val = v;
    n->next = s;
    return n;
}

Stack* pop(Stack *s, int *v) {
    if(!s) return NULL;
    Stack *tmp = s;
    *v = s->val;
    s = s->next;
    free(tmp);
    return s;
}

Stack* pairImpair(Stack *s) {
    Stack *even = NULL;
    Stack *odd = NULL;
    int x;

    while(s) {
        s = pop(s, &x);
        if(x % 2 == 0) even = push(even, x);
        else odd = push(odd, x);
    }

    while(odd) {
        odd = pop(odd, &x);
        even = push(even, x);
    }

    return even;
}