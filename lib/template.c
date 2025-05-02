#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dbg(M, ...)                                                            \
  fprintf(stderr, "[dbg: %i] " M "\n", __LINE__, ##__VA_ARGS__)

char buf[1024];

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  char *line = fgets(buf, sizeof(buf) / sizeof(buf[0]), stdin);
  assert(line != NULL);
  line[strcspn(line, "\n")] = 0;
  dbg("%s", line);
  long n = strtol(line, &line, 10);
  long m = strtol(line, &line, 10);
  dbg("%ld %ld", n, m);
  printf("result\n");
  return 0;
}
