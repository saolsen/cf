// As simple as possible dynamic array for cp problems.

#include <assert.h>
#include <stdlib.h>

void arr_push(int **arr, size_t *len, size_t *cap, int val) {
  if (*arr == NULL || len + 1 > cap) {
    *cap = *cap == 0 ? 4 : *cap * 2;
    int *buf = realloc(*arr, *cap);
    assert(buf != NULL);
    *arr = buf;
  }
  *arr[*len++] = val;
}

// When you wanna not pass so many args, you can do.
int *arr = NULL;
size_t arr_len = 0;
size_t arr_cap = 0;
#define push(arr, val) arr_push(&arr, &arr_len, &arr_cap, val);

// If you really just have one, you can just define the push over globals.