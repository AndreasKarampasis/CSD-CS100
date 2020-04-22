#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equals(a, b) strcmp(a, b) == 0

void encrypt() {
  char str[1024];
  int c, i, count, n;
  i = 0;
  while ((c = getchar()) != '\n') {
    str[i] = (char)c;
    i++;
  }
  str[i] = '\0';
  n = sizeof(str);
  for (i = 0; i < n && str[i] != '\0'; i++) {
    count = 1;
    while (str[i] == str[i + 1]) {
      count++;
      i++;
    }
    printf("%d%c", count, str[i]);
  }
  puts("");
}

void decrypt() {
  char str[1024];
  char foo[2];
  int c, n, i, j, s;
  i = 0;
  while ((c = getchar()) != '\n') {
    str[i] = (char)c;
    i++;
  }
  str[i] = '\0';
  foo[1] = '\0';
  i = 0;
  while (str[i] != '\0') {
    s = 0;
    while (isdigit(str[i])) {
      foo[0] = str[i];
      s *= 10;
      s += atoi(foo);
      i++;
    }
    for (j = 0; j < s; j++) {
      printf("%c", str[i]);
    }
    i++;
  }
  puts("");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    return 0;
  }
  if (equals(argv[1], "e")) {
    encrypt();
  } else if (equals(argv[1], "d")) {
    decrypt();
  }

  return 0;
}
