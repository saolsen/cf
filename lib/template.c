#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[1024];

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  char *line = fgets(buf, sizeof(buf) / sizeof(buf[0]), stdin);
  assert(line != NULL);
  line[strcspn(line, "\n")] = 0;
  fprintf(stderr, "%s", line);
  long n = strtol(line, &line, 10);
  long m = strtol(line, &line, 10);
  fprintf(stderr, "%ld %ld\n", n, m);
  return 0;
}
