#define _CRT_SECURE_NO_DEPRECATE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char buf[1024];

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif
    char *line = fgets(buf, 1024, stdin);
    long n = strtol(line, NULL, 10);

    if (n % 2 == 0) {
        printf("Mahmoud\n");
    } else {
        printf("Ehab\n");
    }
    return 0;
}
