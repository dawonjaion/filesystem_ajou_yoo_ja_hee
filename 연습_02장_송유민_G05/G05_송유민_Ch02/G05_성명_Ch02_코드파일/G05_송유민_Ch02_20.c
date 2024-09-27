#include <stdio.h>

int main() {
	char fir[100];
	char sec[100];
	int i = 0;
	for (fir[i] = getchar(); fir[i] != '\n'; fir[i] = getchar()) {
		i++;
	}
	i = 0;
	for (sec[i] = getchar(); sec[i] != '\n'; sec[i] = getchar()) {
		i++;
	}
	i = 0;
	while (1) {
		if (fir[i] != sec[i]) {
			printf("different\n");
			break;
		}
		if (fir[i] == '\n') {
			if (fir[i] == sec[i]) {
				printf("same\n");
				break;
			}
		}
		i++;
		
	}
	return 0;
}
