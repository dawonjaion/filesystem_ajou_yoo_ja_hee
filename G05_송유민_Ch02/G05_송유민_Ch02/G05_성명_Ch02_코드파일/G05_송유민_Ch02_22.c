
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void print(char* arr, int p) {

	char* ptr = arr;

	for (int i = 0; i <= p - 1; i++) {

		if (*ptr >= 'A' && *ptr <= 'Z') {

			*ptr += 32;
			printf("%c", *ptr);
			ptr++;
		}
		else if (*ptr >= 'a' && *ptr <= 'z') {

			*ptr -= 32;
			printf("%c", *ptr);
			ptr++;
		}
		else {
			printf("%c", *ptr);
			ptr++;
		}
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