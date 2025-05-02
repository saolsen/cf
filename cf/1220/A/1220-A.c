#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (x) < (y) ? (x) : (y)

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  char num[16];
  char *out;
  out = fgets(num, 16, stdin);
  assert(out != NULL);

  size_t num_chars = (size_t)strtol(num, NULL, 10);

  char *line = (char *)malloc(num_chars + 1);

  out = fgets(line, (int)num_chars + 1, stdin);
  assert(out != NULL);

  int z = 0;
  int e = 0;
  int r = 0;
  int o = 0;
  int n = 0;

  for (size_t i = 0; i < (size_t)num_chars; i++) {
    switch (line[i]) {
    case 'z': {
      z++;
      break;
    }
    case 'e': {
      e++;
      break;
    }
    case 'r': {
      r++;
      break;
    }
    case 'o': {
      o++;
      break;
    }
    case 'n': {
      n++;
      break;
    }
    default: {
      assert(0);
    }
    }
  }

  int ones = MIN(o, MIN(n, e));
  o -= ones;
  n -= ones;
  e -= ones;

  int zeros = MIN(z, MIN(e, MIN(r, o)));
  z -= zeros;
  e -= zeros;
  r -= zeros;
  o -= zeros;

  for (int i = 0; i < ones; i++) {
    printf("1 ");
  }
  for (int i = 0; i < zeros; i++) {
    printf("0 ");
  }
  printf("\n");
  free(line);
  return 0;
}
