#include <stdio.h>

int power(int a, int n) {
    if(n == 0) return 1;
    return a * power(a, n - 1);
}

int fastPower(int a, int n) {
    if(n == 0) return 1;
    if(n % 2 == 0) return fastPower(a * a, n / 2);
    return a * fastPower(a * a, n / 2);
}

int sum(int a, int n) {
    if(n == 0) return 1;
    return power(a, n) + sum(a, n - 1);
}

int main() {
    printf("%d\n", power(2,3));
    printf("%d\n", fastPower(2,3));
    printf("%d\n", sum(2,3));
    return 0;
}