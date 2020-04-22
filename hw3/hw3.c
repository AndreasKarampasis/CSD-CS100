#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#define SIZE atoi(argv[2])
#define UPPER 7
#define LOWER 1
#define equals(a, b) strcmp(a, b) == 0

void createMatrix(int n) {
        int i, j;
        int **matrix;
        matrix = malloc(n * n * sizeof(int));
        for (i = 0; i < n; i++) {
                matrix[i] = malloc(n * sizeof(int));
        }
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        matrix[i][j] = (rand() %                \
                                        (UPPER - LOWER + 1))    \
                                       + LOWER;
                }
                for (j = 0; j < i; j++) {
                        matrix[i][j] = 0;
                }
        }
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        printf("%d ", matrix[i][j]);
                }
                puts("");
        }

}

int calculateDeterminant () {
	int size, i, j;
	int det;
	int arr[10][10];
	det = 1;
	scanf("%d", &size);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (i == j && arr[i][j] != 0) {
				det *= arr[i][j];
			}
		}
	}
	return det;
}

int main(int argc, char **argv) {
        int n;
        srand(time(NULL));
	if (argc < 2) {
		puts("No arguments found");
		return 1;
	}
        if (equals(argv[1], "-create")) {
		if (argc != 3) {
			puts("No array size provided");
			return 1;
		}
                n = SIZE;
		if (n < 2 || n > 10) {
			puts("Not valid array size");
			return 1;
		}
                createMatrix(n);
        }
	if (equals(argv[1], "-calculate")) {
		n = calculateDeterminant();
		printf("%d\n", n);
	}
        return 0;
}

