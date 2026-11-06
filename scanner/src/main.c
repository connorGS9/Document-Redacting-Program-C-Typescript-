#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include "scan.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "There was an error\n");
    }

    return 0;
}