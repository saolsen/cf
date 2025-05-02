#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

char buf[1024];

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  char *line = fgets(buf, 1024, stdin);
  long lh = strtol(line, &line, 10);
  long rh = strtol(line, &line, 10);
  long ad = strtol(line, &line, 10);

  long less, more;
  less = MIN(lh, rh);
  more = MAX(lh, rh);
  long diff = more - less;
  // diff between is bigger than the number ad. Put all ad on the small team,
  // that's the max size
  if (diff > ad) {
    assert(less + ad <= more);
    printf("%li\n", (less + ad) * 2);
    return 0;
  }

  // diff is <= num ad. Draft diff amount first, then divide any extras.
  ad -= diff;
  less += diff;
  assert(less == more);
  long extras = ad / 2;
  printf("%li\n", (less + extras) * 2);
  return 0;
}
