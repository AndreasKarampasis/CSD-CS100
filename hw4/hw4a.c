#include <stdio.h>
#define MAX 100
#define MAGIC_NUMBER(n) (n * (n * n + 1) / 2)

int checkRows(int arr[MAX][MAX], int n) {
  int i, j, sum, flag;
  sum = 0;
  flag = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sum += arr[i][j];
    }
    if (sum == MAGIC_NUMBER(n)) {
      printf("ROW %d YES\n", i + 1);
    } else {
      printf("ROW %d NO\n", i + 1);
      flag = 0;
    }
    sum = 0;
  }
  return flag;
}

int checkColumns(int arr[MAX][MAX], int n) {
  int i, j, sum, flag;
  sum = 0;
  flag = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sum += arr[j][i];
    }
    if (sum == MAGIC_NUMBER(n)) {
      printf("COLUMN %d YES\n", i + 1);
    } else {
      printf("COLUMN %d NO\n", i + 1);
      flag = 0;
    }
    sum = 0;
  }
  return flag;
}

int checkDiag1(int arr[MAX][MAX], int n) {
  int i, sum;
  int flag;
  sum = 0;
  for (i = 0; i < n; i++) {
    sum += arr[i][i];
  }
  if (sum == MAGIC_NUMBER(n)) {
    puts("DIAG1 YES");
    flag = 1;
  } else {
    puts("DIAG1 NO");
    flag = 0;
  }
  return flag;
}

int checkDiag2(int arr[MAX][MAX], int n) {
  int i, sum;
  int flag;
  sum = 0;
  for (i = 0; i < n; i++) {
    sum += arr[i][n - i - 1];
  }
  if (sum == MAGIC_NUMBER(n)) {
    puts("DIAG2 YES");
    flag = 1;
  } else {
    puts("DIAG2 NO");
    flag = 0;
  }
  return flag;
}

int isUnique(int arr[MAX][MAX], int n) {
  int i, j, sum, c;
  int a[MAX * MAX];
  c = 0;
  sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[c] = arr[i][j];
      if (a[c] > (n * n)) {
        puts("UNIQUE NO");
        return 0;
      }
      c++;
    }
  }

  for (i = 0; i < n * n; i++) {
    for (j = i + 1; j < n * n; j++) {
      if (a[i] == a[j]) {
        puts("UNIQUE NO");
        return 0;
      }
    }
  }
  puts("UNIQUE YES");
  return 1;
}

int main() {
  int arr[MAX][MAX];
  int flags[5];
  int n, i, j;
  int magicNumber, sum;
  sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  flags[0] = checkRows(arr, n);
  flags[1] = checkColumns(arr, n);
  flags[2] = checkDiag1(arr, n);
  flags[3] = checkDiag2(arr, n);
  flags[4] = isUnique(arr, n);
  if (flags[0] && flags[1] && flags[2] && flags[3] && flags[4]) {
    puts("MAGIC YES");
  } else {
    puts("MAGIC NO");
  }
  return 0;
}