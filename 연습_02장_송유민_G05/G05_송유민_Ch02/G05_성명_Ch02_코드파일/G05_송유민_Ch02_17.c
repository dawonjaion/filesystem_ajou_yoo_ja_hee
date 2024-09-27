#include <stdio.h>
#include <stdlib.h>

void count(int m[], int e[], int k[], int s[], double a[]) {
    int random;
    for (int i = 0; i < 10; i++) {
        m[i] = rand() % 101;
        e[i] = rand() % 101;
        k[i] = rand() % 101;
    }
    for (int i = 0; i < 10; i++) {
        s[i] = m[i] + e[i] + k[i];
    }
    for (int i = 0; i < 10; i++) {
        a[i] = (float)s[i] / 3;
    }

    return;
}

int main() {
    int math[10];
    int english[10];
    int korean[10];
    int sum[10];
    double ave[10];


    count(math, english, korean, sum, ave);

    printf("\t\b학번\t국어\t영어\t수학\t총점\t평균");
    printf("\n*************************************\n");
    for (int i = 0; i < 10; i++) {
        printf("\t%d\t%5d\t%5d\t%5d\t%5d\t%.1f\n", i + 1, korean[i], english[i], math[i], sum[i], ave[i]);
    }

    return 0;
}