#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void print(char* arr, int t) {

	for (int i = t - 1; i >= 0; i--) {

		printf("%c", *(arr + i));
	}
}

int main() {

	char a[100];

	printf("Enter a string.\n");
	scanf("%[^\n]s", &a);

	int k = strlen(a);

	print(a, k);

	return 0;
}