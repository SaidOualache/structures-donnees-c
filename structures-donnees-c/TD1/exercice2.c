#include <stdio.h>

typedef struct {
    int hh;
    int mm;
    int ss;
} Heure;

int HeureEnSecondes(Heure h) {
    return h.hh * 3600 + h.mm * 60 + h.ss;
}

Heure SecondesEnHeure(int sec) {
    Heure h;
    h.hh = sec / 3600;
    sec = sec % 3600;
    h.mm = sec / 60;
    sec = sec % 60;
    h.ss = sec;
    return h;
}

Heure Addition(Heure h1, Heure h2) {
    int total = HeureEnSecondes(h1) + HeureEnSecondes(h2);
    return SecondesEnHeure(total);
}

Heure Difference(Heure h1, Heure h2) {
    int total = HeureEnSecondes(h1) - HeureEnSecondes(h2);
    if(total < 0) total = -total;
    return SecondesEnHeure(total);
}

int main() {
    Heure h1 = {1, 20, 30};
    Heure h2 = {2, 10, 15};

    Heure h3 = Addition(h1, h2);
    Heure h4 = Difference(h1, h2);

    printf("%d:%d:%d\n", h3.hh, h3.mm, h3.ss);
    printf("%d:%d:%d\n", h4.hh, h4.mm, h4.ss);

    return 0;
}