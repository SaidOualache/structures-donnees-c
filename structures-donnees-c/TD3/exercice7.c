#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    char val;
    struct stack *next;
} Stack;

typedef struct qnode {
    char val;
    struct qnode *next;
} QNode;

typedef struct queue {
    QNode *front;
    QNode *rear;
} Queue;

Stack* push(Stack *s, char v) {
    Stack *n = (Stack*)malloc(sizeof(Stack));
    n->val = v;
    n->next = s;
    return n;
}

Stack* pop(Stack *s, char *v) {
    Stack *tmp = s;
    *v = s->val;
    s = s->next;
    free(tmp);
    return s;
}

Queue* createQ() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, char v) {
    QNode *n = (QNode*)malloc(sizeof(QNode));
    n->val = v;
    n->next = NULL;

    if(!q->rear) {
        q->front = q->rear = n;
        return;
    }

    q->rear->next = n;
    q->rear = n;
}

int dequeue(Queue *q, char *v) {
    if(!q->front) return 0;

    QNode *tmp = q->front;
    *v = tmp->val;
    q->front = q->front->next;

    if(!q->front) q->rear = NULL;

    free(tmp);
    return 1;
}

int isPalindrome(char s[]) {
    int n = strlen(s);
    int i;
    Stack *st = NULL;
    Queue *q = createQ();
    char a, b;

    for(i = 0; i < n; i++) {
        enqueue(q, s[i]);
    }

    for(i = 0; i < n/2; i++) {
        dequeue(q, &a);
        st = push(st, a);
    }

    if(n % 2 != 0) dequeue(q, &a);

    for(i = 0; i < n/2; i++) {
        dequeue(q, &a);
        st = pop(st, &b);
        if(a != b) return 0;
    }

    return 1;
}