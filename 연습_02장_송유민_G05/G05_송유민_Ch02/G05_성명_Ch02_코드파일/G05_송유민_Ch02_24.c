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

	if (p == 0) printf("목록이 없습니다.\n");
	else {
		for (int i = 0; i < p; i++) {

			printf("목록 %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		}
	}

}

void add(list s[]) {

	printf("목록을 입력하세요.\n");

	printf("이름 : ");
	scanf(" %[^\n]s", s[p].name);
	

	printf("전화번호 : ");
	scanf(" %[^\n]s", s[p].phonenumber);
	

	printf("주소 : ");
	scanf(" %[^\n]s", s[p].address);
	

	printf("생일 : ");
	scanf(" %[^\n]s", s[p].birthday);
	

	printf("추가되었습니다.\n");

	p++;
}

void detect(list s[]) {

	char k[100];
	int j = 0;

	if (p == 0) {
		printf("목록이 없습니다.\n");
		return;
	}
	

	printf("탐색할 항목을 입력하세요.\n");
	scanf("%[^\n]s", &k);

	for (int i = 0; i < p; i++) {

		if (strcmp(k, s[i].name) == 0) printf("목록 %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;

		if (strcmp(k, s[i].phonenumber) == 0) printf("목록 %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;

		if (strcmp(k, s[i].address) == 0) printf("목록 %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;

		if (strcmp(k, s[i].birthday) == 0) printf("목록 %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
		else if (strcmp(k, s[i].name) != 0) j++;
	}
	if (j == 4 * p) printf("찾으시는 항목은 없습니다.\n");
}

void delete(list s[]) {

	int k;

	if (p == 0) {
		printf("삭제할 목록이 없습니다.\n");
		return;
	}
	

	printf("어떤 목록을 삭제하겠습니까?\n");
	for (int i = 0; i < p; i++) {

		printf("목록 %d : %s, %s, %s, %s\n", i + 1, s[i].name, s[i].phonenumber, s[i].address, s[i].birthday);
	}

	scanf("%d", &k);

	if (k <= p && k > 0) {
	
		printf("목록 %d는 삭제되었습니다.\n", k);

		p--;
		for (int i = k; i <= p; i++) {

			s[i - 1] = s[i];
		}
		
	}
	else printf("목록 %d는 없습니다.\n", k);

}

int main() {

	int a;
	list sys[100];

	while (1) {

		printf("\n1. 목록보기  ||  2. 추가하기  ||  3. 탐색하기  ||  4. 삭제하기\n입력하세요(0 입력시 프로그램 종료) : ");
		
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

