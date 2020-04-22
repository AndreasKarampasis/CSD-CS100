#include <stdio.h>

int main() {
	int n, reversed = 0;
	scanf("%d", &n);
	while(n != 0) {
		reversed *= 10;
		reversed += n % 10;
		n = n / 10;
	}
	printf("%d\n", reversed);
	return 0;
}
