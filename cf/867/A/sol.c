#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: Probably wanna just learn a little c++ and use it for this, easier
// input handling.

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif

  char num[16];
  char *out;
  out = fgets(num, 16, stdin);
  assert(out != NULL);

  fprintf(stderr, "num: %s\n", num);
  int num_days = (int)strtol(num, NULL, 10);
  fprintf(stderr, "num: %i\n", num_days);

  char *line = (char *)malloc((size_t)num_days + 1);
  out = fgets(line, num_days + 1, stdin);
  assert(out != NULL);

  fprintf(stderr, "line: %s\n", line);

  char prev = out[0];
  int s_to_f = 0;
  int f_to_s = 0;
  for (int i = 1; i < num_days; i++) {
    if (out[i] == prev) {
      continue;
    }
    if (prev == 'F') {
      f_to_s++;
    } else {
      s_to_f++;
    }
    prev = out[i];
  }

  if (s_to_f > f_to_s) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  free(line);
  return 0;
}
