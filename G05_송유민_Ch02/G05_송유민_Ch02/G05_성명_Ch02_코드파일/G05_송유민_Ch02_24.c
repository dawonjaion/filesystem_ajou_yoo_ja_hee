#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int p = 0;
typedef struct {

	char name[100];
	char phonenumber[100];
	char address[100];
	char birthday[100];
}list;

void showlist(list s[]) {

	if (p == 0) printf("����� �����ϴ�.\n");
	else {
		for (int i = 0; i < p; i++) {

			printf("��� %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		}
	}

}

void add(list s[]) {

	printf("����� �Է��ϼ���.\n");

	printf("�̸� : ");
	scanf(" %[^\n]s", s[p].name);
	

	printf("��ȭ��ȣ : ");
	scanf(" %[^\n]s", s[p].phonenumber);
	

	printf("�ּ� : ");
	scanf(" %[^\n]s", s[p].address);
	

	printf("���� : ");
	scanf(" %[^\n]s", s[p].birthday);
	

	printf("�߰��Ǿ����ϴ�.\n");

	p++;
}

void detect(list s[]) {

	char k[100];
	int j = 0;

	if (p == 0) {
		printf("����� �����ϴ�.\n");
		return;
	}
	

	printf("Ž���� �׸��� �Է��ϼ���.\n");
	scanf("%[^\n]s", &k);

	for (int i = 0; i < p; i++) {

		if (strcmp(k, s[i].name) == 0) printf("��� %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;

		if (strcmp(k, s[i].phonenumber) == 0) printf("��� %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;

		if (strcmp(k, s[i].address) == 0) printf("��� %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;

		if (strcmp(k, s[i].birthday) == 0) printf("��� %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;
	}
	if (j == 4 * p) printf("ã���ô� �׸��� �����ϴ�.\n");
}

void delete(list s[]) {

	int k;

	if (p == 0) {
		printf("������ ����� �����ϴ�.\n");
		return;
	}
	

	printf("� ����� �����ϰڽ��ϱ�?\n");
	for (int i = 0; i < p; i++) {

		printf("��� %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
	}

	scanf("%d", &k);

	if (k <= p && k > 0) {
	
		printf("��� %d�� �����Ǿ����ϴ�.\n", k);

		p--;
		for (int i = k; i <= p; i++) {

			s[i - 1] = s[i];
		}
		
	}
	else printf("��� %d�� �����ϴ�.\n", k);

}

int main() {

	int a;
	list sys[100];

	while (1) {

		printf("\n1. ��Ϻ���  ||  2. �߰��ϱ�  ||  3. Ž���ϱ�  ||  4. �����ϱ�\n�Է��ϼ���(0 �Է½� ���α׷� ����) : ");
		
		scanf("%d", &a);
		getchar();

		if (a == 0) break;
		else if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4) continue;
		else if (a == 1) showlist(sys);
		else if (a == 2) add(sys);
		else if (a == 3) detect(sys);
		else if (a == 4) delete(sys);
	}

	return 0;
}

