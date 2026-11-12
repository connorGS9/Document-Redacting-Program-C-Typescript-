#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include "scan.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "There was an error\n");
        return 2;
    }

    unsigned char* buf = NULL;
    size_t len = 0;
    int result = scan_all(stdin, &buf, &len);
    if (result != 0) {
        fprintf(stderr, "Scan all function failed.\n");
        return 2;
    }
    fprintf(stderr, "The length of the buffer is: %zu\n", len);
    free(buf);
    return 0;
}