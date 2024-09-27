#include<stdio.h>
void switch_num(int* a, int* b) {
	int n1 = *a;
	*a = *b;
	*b = n1;
	return;
}
int main() {
	int num1 = 10;
	int num2 = 100;
	printf("Before switch_num : num1 == %d, num2 == %d\n", num1, num2);
	switch_num(&num1, &num2);
	printf("After switch_num : num1 == %d, num2 == %d\n", num1, num2);


	return 0;
}
