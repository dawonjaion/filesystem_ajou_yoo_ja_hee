#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 5

int RQ[MAX];  // RQ (Right Queue)에 들어갈 숫자들
int MS[MAX];  // 중간 스택 (Main Stack)
int LQ[MAX];  // LQ (Left Queue)에 출력할 수열을 저장
int N;        // 사용자로부터 입력받을 자연수 개수
int top = -1; // MS 스택의 최상위 인덱스
int count = 0; // 가능한 스택 수열 개수

// 스택 함수들
void push(int value) {
    if (top < MAX - 1) {
        MS[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return MS[top--];
    }
    return -1; // 스택이 비었을 때 -1 반환
}

int isEmpty() {
    return top == -1;
}

// 완전한 수열을 출력하는 함수
void printLQ() {
    printf("%d: ", ++count);
    for (int i = 0; i < N; i++) {
        printf("%d", LQ[i]);
    }
    printf("\n");
}

// 재귀적으로 가능한 모든 수열 생성
void generateSequences(int rqIndex, int lqIndex) {
    // 모든 숫자가 LQ에 다 채워졌을 때 출력
    if (lqIndex == N) {
        printLQ();
        return;
    }

    // RQ에서 MS로 이동
    if (rqIndex < N) {
        push(RQ[rqIndex]);
        generateSequences(rqIndex + 1, lqIndex);
        pop(); // 백트래킹
    }

    // MS에서 LQ로 이동
    if (!isEmpty()) {
        LQ[lqIndex] = pop();
        generateSequences(rqIndex, lqIndex + 1);
        push(LQ[lqIndex]); // 백트래킹
    }
}

int main() {
    while (1) {
        printf("*** 숫자 수 (5 이하 자연수), N = ");
        scanf("%d", &N);

        if (N == 0) {
            printf("Bye!!!\n");
            break;
        }
        else if (N > 5) {
            printf("+++ 5 이하 자연수를 입력하세요!\n");
            continue;
        }

        // 초기화
        for (int i = 0; i < N; i++) {
            RQ[i] = i + 1;
        }
        count = 0;
        generateSequences(0, 0);

        printf("# of Stack Numbers = %d\n", count);
    }

    return 0;
}
