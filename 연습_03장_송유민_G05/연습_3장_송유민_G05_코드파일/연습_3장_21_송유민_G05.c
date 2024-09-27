#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DEGREE 50

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

void multPoly();  // ���׽��� �Է¹ް� ���� �� ����� ����ϴ� �Լ�

void main() {
    multPoly();
}

void multPoly() {
    polynomial a, b, c = { 0 };
    int i, j;

    // ù ��° ���׽� �Է�
    printf("ù ��° ���׽��� �ְ� ������ �Է��ϼ���: ");
    scanf("%d", &a.degree);
    for (i = 0; i <= a.degree; i++) {
        printf("x^%d ���� ����� �Է��ϼ���: ", a.degree - i);
        scanf("%f", &a.coef[i]);
    }

    // �� ��° ���׽� �Է�
    printf("�� ��° ���׽��� �ְ� ������ �Է��ϼ���: ");
    scanf("%d", &b.degree);
    for (i = 0; i <= b.degree; i++) {
        printf("x^%d ���� ����� �Է��ϼ���: ", b.degree - i);
        scanf("%f", &b.coef[i]);
    }

    // �� ���׽� ���ϱ�
    c.degree = a.degree + b.degree; // ��� ���׽��� �ְ� ������ �� ���׽� ������ ��
    for (i = 0; i <= a.degree; i++) {
        for (j = 0; j <= b.degree; j++) {
            c.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    // ù ��° ���׽� ���
    printf("ù ��° ���׽�: ");
    for (i = 0; i <= a.degree; i++) {
        printf("%2.0fx^%d", a.coef[i], a.degree - i);
        if (i < a.degree)
            printf(" + ");
    }
    printf("\n");

    // �� ��° ���׽� ���
    printf("�� ��° ���׽�: ");
    for (i = 0; i <= b.degree; i++) {
        printf("%2.0fx^%d", b.coef[i], b.degree - i);
        if (i < b.degree)
            printf(" + ");
    }
    printf("\n");

    // ���� ��� ���
    printf("-------------------------------- �� ���� ���ϸ�\n");
    for (i = 0; i <= c.degree; i++) {
        printf("%2.0fx^%d", c.coef[i], c.degree - i);
        if (i < c.degree)
            printf(" + ");
    }
    printf("\n");
}
