#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacci(int* current, int* previous, int a, int i) {
    if (i == a) {
        return *current;
    }
    int temp = *current;
    *current += *previous;
    *previous = temp;
    return fibonacci(current, previous, a, i + 1);
}

int main() {
    int current = 1;
    int previous = 0;
    int a;
    printf("피보나치를 실행할 횟수를 입력해주세요\n");
    scanf("%d", &a);
    printf("%d\n", fibonacci(&current, &previous, a-1, 0));
    return 0;
}
