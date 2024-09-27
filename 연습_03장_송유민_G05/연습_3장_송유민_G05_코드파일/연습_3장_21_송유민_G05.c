#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DEGREE 50

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

void multPoly();  // 다항식을 입력받고 곱한 후 결과를 출력하는 함수

void main() {
    multPoly();
}

void multPoly() {
    polynomial a, b, c = { 0 };
    int i, j;

    // 첫 번째 다항식 입력
    printf("첫 번째 다항식의 최고 차수를 입력하세요: ");
    scanf("%d", &a.degree);
    for (i = 0; i <= a.degree; i++) {
        printf("x^%d 항의 계수를 입력하세요: ", a.degree - i);
        scanf("%f", &a.coef[i]);
    }

    // 두 번째 다항식 입력
    printf("두 번째 다항식의 최고 차수를 입력하세요: ");
    scanf("%d", &b.degree);
    for (i = 0; i <= b.degree; i++) {
        printf("x^%d 항의 계수를 입력하세요: ", b.degree - i);
        scanf("%f", &b.coef[i]);
    }

    // 두 다항식 곱하기
    c.degree = a.degree + b.degree; // 결과 다항식의 최고 차수는 두 다항식 차수의 합
    for (i = 0; i <= a.degree; i++) {
        for (j = 0; j <= b.degree; j++) {
            c.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    // 첫 번째 다항식 출력
    printf("첫 번째 다항식: ");
    for (i = 0; i <= a.degree; i++) {
        printf("%2.0fx^%d", a.coef[i], a.degree - i);
        if (i < a.degree)
            printf(" + ");
    }
    printf("\n");

    // 두 번째 다항식 출력
    printf("두 번째 다항식: ");
    for (i = 0; i <= b.degree; i++) {
        printf("%2.0fx^%d", b.coef[i], b.degree - i);
        if (i < b.degree)
            printf(" + ");
    }
    printf("\n");

    // 곱한 결과 출력
    printf("-------------------------------- 두 식을 곱하면\n");
    for (i = 0; i <= c.degree; i++) {
        printf("%2.0fx^%d", c.coef[i], c.degree - i);
        if (i < c.degree)
            printf(" + ");
    }
    printf("\n");
}
