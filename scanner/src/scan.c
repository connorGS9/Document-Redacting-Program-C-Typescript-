#define _POSIX_C_SOURCE 200809L
#include "scan.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int versionNumber(int vn) {
    return vn;
}

int scan_all(FILE *in, unsigned char **out_buf, size_t *out_len) {
    size_t len = 0;
    size_t cap = 4096;
    unsigned char* buf =  malloc(cap);
    if (buf == NULL) return -1;
   for (;;) {
        if (len == cap) {
            // Realloc
            unsigned char* next = realloc(buf, cap * 2);
            if (next == NULL) {
                free(buf);
                return -1;
            } else {
                buf = next;
                cap *= 2;
            }
        }
        size_t n = fread(buf + len, 1, cap - len, in);
        if (n == 0) break;
        len += n;
    }

    if (ferror(in)) {
        free(buf);
        return -1;
    }
    *out_buf = buf;
    *out_len = len;
    return 0;
}