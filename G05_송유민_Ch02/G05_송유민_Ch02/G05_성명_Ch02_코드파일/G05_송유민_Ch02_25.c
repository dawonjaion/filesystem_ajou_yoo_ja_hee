
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int summ(int* sum, int a, int i) {
    if (i == a) {
        return *sum;
    }
    *sum += i;
    return summ(sum, a, i + 1);
}

int main() {
    int sum = 0;
    int a;
    printf("숫자를 입력해주세요\n");
    scanf("%d", &a);
    printf("%d\n", summ(&sum, a+1,0));

    return 0;
}
