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
  assert(strlen(line) == 26);
  char *kb1 = _strdup(line);

  line = fgets(buf, sizeof(buf) / sizeof(buf[0]), stdin);
  assert(line != NULL);
  line[strcspn(line, "\n")] = 0;
  assert(strlen(line) == 26);
  char *kb2 = _strdup(line);

  char key_map[128] = {};
  for (size_t i = 0; i < 26; i++) {
    key_map[(size_t)(kb1[i])] = kb2[i];
  }

  size_t cap_offset = 'a' - 'A';

  char *word = fgets(buf, sizeof(buf) / sizeof(buf[0]), stdin);
  assert(word != NULL);
  word[strcspn(word, "\n")] = 0;
  fprintf(stderr, "%s\n", word);

  for (size_t i = 0; i < strlen(word); i++) {
    if (word[i] >= 'A' && word[i] <= 'Z') {
      // capital letter
      char lc = word[i] + cap_offset;
      char mapped = key_map[(size_t)lc];
      char c = mapped - cap_offset;
      printf("%c", c);
    } else if (word[i] >= 'a' && word[i] <= 'z') {
      // lowercase letter
      char c = key_map[(size_t)word[i]];
      printf("%c", c);
    } else {
      // numbers and maybe space if it shows up.
      printf("%c", word[i]);
    }
  }
  printf("\n");
  return 0;
}