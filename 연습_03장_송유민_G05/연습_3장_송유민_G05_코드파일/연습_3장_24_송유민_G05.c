#include<stdio.h>


int main_3_24() {
	int arr[7][4] = { {0, 0, 0, 9},{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 7, 0}, {0, 0, 0, 0}, {3, 0, 0, 0}, {0, 0, 0, 0} };
	int count = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]) {
				count++;
			}
		}
	}
	printf("원래의 행렬\n");
	for (int i = 0; i < 7; i++) {
		printf("|\t%d\t%d\t%d\t%d\t|\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
	}
	printf("변환 후\n");

	int save[4][3];
	count = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]) {
				save[count][0] = i;
				save[count][1] = j;
				save[count][2] = arr[i][j];

				count++;
			}
		}
	}
	printf("|\t행\t열\t값\t|\n");
	for (int i = 0; i < 4; i++) {
		printf("|\t%d\t%d\t%d\t|\n", save[i][0], save[i][1], save[i][2]);
	}
	return 0;
}