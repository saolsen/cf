// Need a good way to write all these parsers quickly and easily.
// Don't really wanna build a whole lexer/parser combinator thing because it's a
// lot to paste into a file.
// Wanna probably stick to the standard library. And even use the insecure stuff
// like strtok and scanf because I don't need any error handling or anything, I
// just need to parse an exact format that I know will be correct.

// Freopen is really nice for test input.
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[1024];

// Read a line from stdin.
// Reuses same buf each call so parse it to something else before calling again.
char *read_line() {
  char *line = fgets(buf, 1024, stdin);
  assert(line != NULL);
  line[strcspn(line, "\n")] = 0;
  return line;
}

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif

  char *line = read_line();
  printf("line: %s\n", line);
  long d = strtol(line, NULL, 10);
  printf("%li\n", d);
  line = read_line();
  printf("line: %s\n", line);
}
