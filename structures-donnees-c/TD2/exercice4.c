#include <stdio.h>

int f1(int n) {
    if(n == 0) return 1;
    return 2 * f1(n - 1);
}

int f2(int n) {
    if(n == 0) return 1;
    return f2(n - 1) + f2(n - 1);
}

int main() {
    printf("%d\n", f1(3));
    printf("%d\n", f2(3));
    return 0;
}