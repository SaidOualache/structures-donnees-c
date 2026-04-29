#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int abs;
    int ord;
} Point;

Point SaisirPoint() {
    Point p;
    scanf("%d %d", &p.abs, &p.ord);
    return p;
}

void AfficherPoint(Point p) {
    printf("(%d,%d)\n", p.abs, p.ord);
}

float distance(Point p) {
    return sqrt(p.abs * p.abs + p.ord * p.ord);
}

float distancePtr(Point *p) {
    return sqrt(p->abs * p->abs + p->ord * p->ord);
}

void tritab(Point t[], int taille) {
    int i, j;
    Point tmp;
    for(i = 0; i < taille - 1; i++) {
        for(j = i + 1; j < taille; j++) {
            if(distance(t[i]) > distance(t[j])) {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

int main() {
    int i, taille;
    Point p = SaisirPoint();
    AfficherPoint(p);

    scanf("%d", &taille);

    Point Tstat[100];
    Point *Tdyn = (Point*)malloc(taille * sizeof(Point));

    srand(time(NULL));

    for(i = 0; i < taille; i++) {
        Tstat[i].abs = rand() % 100;
        Tstat[i].ord = rand() % 100;
    }

    for(i = 0; i < taille; i++) {
        Tdyn[i].abs = rand() % 100;
        Tdyn[i].ord = rand() % 100;
    }

    for(i = 0; i < taille; i++) {
        AfficherPoint(Tdyn[i]);
    }

    tritab(Tdyn, taille);

    for(i = 0; i < taille; i++) {
        AfficherPoint(Tdyn[i]);
    }

    free(Tdyn);
    return 0;
}