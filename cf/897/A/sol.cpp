#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 128
char buf[BUF_SIZE];

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("b.in", "r", stdin);
#endif

  char *line;
  line = fgets(buf, BUF_SIZE, stdin);
  assert(line != NULL);

  long n = strtol(line, &line, 10);
  long m = strtol(line, &line, 10);
  fprintf(stderr, "n: %li, m: %li\n", n, m);

  char s[102];
  fgets(s, 102, stdin);
  assert(s[n] == '\n');
  line[n] = NULL;
  fprintf(stderr, "%s\n", s);

  // l r c1 c2
  for (int i = 0; i < m; i++) {
    long l, r;
    char c1, c2;
    line = fgets(buf, BUF_SIZE, stdin);
    assert(line != NULL);
    l = strtol(line, &line, 10);
    r = strtol(line, &line, 10);
    line++;
    c1 = *line++;
    line++;
    c2 = *line;

    fprintf(stderr, "l: %li, r: %li, c1: %c, c2: %c\n", l, r, c1, c2);

    for (int i = l - 1; i <= r - 1; i++) {
      if (s[i] == c1) {
        s[i] = c2;
      }
    }

    fprintf(stderr, "%s\n", s);
  }
  printf("%s\n", s);
  return 0;
}
