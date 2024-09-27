#include <stdio.h>

int main() {
	char a[100][6];
	int j = 0;
	for (int i = 0; i < 5; i++) {
		j = 0;
		for (a[j][i] = getchar(); a[j][i] != '\n'; a[j][i] = getchar()) {
			j++;
		}
	}
	j = 0;
	for (int i = 0; i < 5; i++) {
		while (a[j][i] != '\n') {
			printf("%c", a[j][i]);
			j++;
		}
		j = 0;
		printf("\n");
	}


	return 0;
}
