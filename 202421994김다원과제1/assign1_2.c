#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8  // 최대 행렬 크기
#define MIN_SIZE 3  // 최소 행렬 크기

// 계수행렬 A와 소스벡터 B 출력 함수
void printMatrixWithVector(float matrix[MAX_SIZE][MAX_SIZE], float vector[MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("| %6.2f\n", vector[i]);
    }
}

// 행렬 출력 함수
void printMatrix(float matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 단위행렬 출력 함수 (계수행렬 * 역행렬)
void printIdentityMatrix(float matrix[MAX_SIZE][MAX_SIZE], float inverse[MAX_SIZE][MAX_SIZE], int n) {
    printf("\n*** 단위행렬 (계수행렬 x 역행렬) ***\n");
    float identity[MAX_SIZE][MAX_SIZE] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                identity[i][j] += matrix[i][k] * inverse[k][j];
            }
        }
    }
    printMatrix(identity, n);
}

// 증강행렬 출력 함수
void printAugmentedMatrix(float matrix[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 행렬 초기화 함수 (난수 사용)
void initializeMatrix(float matrix[MAX_SIZE][MAX_SIZE], int n) {
    srand(1);  // 난수 시드 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 3;  // 0 ~ 2 사이의 난수 값
        }
    }
}

// 행렬식 계산 함수 (상삼각행렬로 변환하여 계산)
float calculateDeterminant(float matrix[MAX_SIZE][MAX_SIZE], int n) {
    float det = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][i] == 0) return 0;
            float ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
        det *= matrix[i][i];
    }
    return det;
}

// 상삼각행렬 출력 함수
void printUpperTriangularMatrix(float matrix[MAX_SIZE][MAX_SIZE], int n) {
    float upperMatrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            upperMatrix[i][j] = matrix[i][j];
    calculateDeterminant(upperMatrix, n);  // 상삼각형 변환 수행
    printf("\n*** 상삼각행렬[행렬식: det =1.00] ***\n");
    printMatrix(upperMatrix, n);
}

// 여인수 행렬 계산 함수
void cofactor(float matrix[MAX_SIZE][MAX_SIZE], float cofactorMatrix[MAX_SIZE][MAX_SIZE], int n) {
    float submatrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0;
            for (int x = 0; x < n; x++) {
                if (x == i)
                    continue;
                int subj = 0;
                for (int y = 0; y < n; y++) {
                    if (y == j)
                        continue;
                    submatrix[subi][subj] = matrix[x][y];
                    subj++;
                }
                subi++;
            }
            cofactorMatrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * calculateDeterminant(submatrix, n - 1);
        }
    }
}

// 수반행렬을 사용하여 역행렬 계산 함수
int adjointInverse(float matrix[MAX_SIZE][MAX_SIZE], float inverse[MAX_SIZE][MAX_SIZE], int n) {
    float det = calculateDeterminant(matrix, n);
    if (det == 0) {
        return 0;  // 역행렬이 존재하지 않음을 나타냄
    }
    float cofactorMatrix[MAX_SIZE][MAX_SIZE];
    cofactor(matrix, cofactorMatrix, n);

    // 수반행렬의 전치행렬 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = cofactorMatrix[j][i] / det;
        }
    }
    return 1;  // 역행렬이 존재함을 나타냄
}

// Gauss-Jordan 소거법으로 해 구하기
void gaussJordan(float matrix[MAX_SIZE][MAX_SIZE + 1], float solution[MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        // 주 대각 원소가 1이 되도록 행 조작
        float pivot = matrix[i][i];
        for (int j = 0; j < n + 1; j++) {
            matrix[i][j] /= pivot;
        }

        // 다른 행을 0으로 만듬
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j < n + 1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // 해벡터 X 계산 및 저장
    for (int i = 0; i < n; i++) {
        solution[i] = matrix[i][n];
    }
}

// 소스벡터 B와 해벡터 X 출력 함수
void printSourceAndSolution(float B[MAX_SIZE], float solution[MAX_SIZE], int n) {
    printf("\n*** 소스벡터 B와 해벡터 X ***\n");
    for (int i = 0; i < n; i++) {
        printf("%6.2f | %6.2f\n", B[i], solution[i]);
    }
}

int main() {
    printf("******************************************\n");
    printf("* 과제#1: 다원 1차 연립방정식 구하기     *\n");
    printf("******************************************\n");
    int n;
    while (1) {
        printf("\n+++ NxN 정방행렬 A의 크기, N (3 이상 8 이하의 값 입력): ");
        scanf("%d", &n);

        if (n == 0) {
            printf("Bye!!!\n");
            break;
        }

        if (n < MIN_SIZE || n > MAX_SIZE) {
            printf("^^^ 범위 밖의 크기 N입니다! ^^^\n");
            continue;
        }

        // 행렬 A와 벡터 B 초기화 및 출력
        float matrix[MAX_SIZE][MAX_SIZE];
        float B[MAX_SIZE];
        initializeMatrix(matrix, n);
        for (int i = 0; i < n; i++) {
            B[i] = 1;  // B 벡터를 1로 초기화
        }
        printf("\n*** 계수행렬 A와 소스벡터 B ***\n");
        printMatrixWithVector(matrix, B, n);

        // 행렬식 계산 및 역행렬 가능 여부 확인
        float matrixCopy[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrixCopy[i][j] = matrix[i][j];

        float determinant = calculateDeterminant(matrixCopy, n);
        if (determinant == 0) {
            printf("+++ det(A) = 0: No (unique) Solution +++\n");
            continue;
        }

        // 상삼각행렬 출력
        printUpperTriangularMatrix(matrix, n);

        // 수반행렬 출력
        float cofactorMatrix[MAX_SIZE][MAX_SIZE];
        cofactor(matrix, cofactorMatrix, n);
        printf("\n*** 수반행렬 ***\n");
        printMatrix(cofactorMatrix, n);

        // 역행렬 계산 및 출력
        float inverse[MAX_SIZE][MAX_SIZE];
        adjointInverse(matrix, inverse, n);
        printf("\n*** 역행렬  (1/det(A)x수반행렬)***\n");
        printMatrix(inverse, n);

        // 단위행렬 출력
        printIdentityMatrix(matrix, inverse, n);

        // Gauss-Jordan 소거법을 위한 증강행렬 설정 및 해벡터 X 계산
        float augmentedMatrix[MAX_SIZE][MAX_SIZE + 1];
        float solution[MAX_SIZE];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                augmentedMatrix[i][j] = matrix[i][j];
            }
            augmentedMatrix[i][n] = B[i];
        }

        gaussJordan(augmentedMatrix, solution, n);

        // 소스벡터 B와 해벡터 X 출력
        printSourceAndSolution(B, solution, n);

        printf("\n*** Gauss-Jordan 소거법 ***\n");
        printf("첨가행렬\n");
        printAugmentedMatrix(augmentedMatrix, n);

        printf("\nGauss-Jordan 소거행렬\n");
        printAugmentedMatrix(augmentedMatrix, n);
    }

    return 0;
}
