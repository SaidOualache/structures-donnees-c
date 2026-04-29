#include <stdio.h>

int miniMax(int t[][3], int n, int m) {
    int i, j;
    int max, res;

    for(i = 0; i < n; i++) {
        max = t[i][0];
        for(j = 1; j < m; j++) {
            if(t[i][j] > max) {
                max = t[i][j];
            }
        }

        if(i == 0) {
            res = max;
        } else {
            if(max < res) {
                res = max;
            }
        }
    }
    return res;
}

int main() {
    int t[3][3] = {
        {2,3,4},
        {5,6,7},
        {8,9,10}
    };

    printf("%d\n", miniMax(t, 3, 3));

    return 0;
}