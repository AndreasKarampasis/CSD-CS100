#include <stdio.h>
int main() {
	int i, j;
	int rows;
	int space;
	scanf("%d", &rows);
	for (i = 0; i < rows; i++) {
		space = rows - i - 1;
		for (j = 0; j < space; j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = rows - 1; i > 0; i--) {
		space = rows - i - 1;
		for (j = 0; j <= space; j++) {
			printf(" ");
		}
		for (j = 0; j < i; j++) {
			printf("*");
		}
		for (j = 0; j < i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
