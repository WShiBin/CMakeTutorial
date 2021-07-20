#include <stdlib.h>
#include <string.h>
#include "header.h"

#if HAVE_STDIO_H
#include <stdio.h>
#endif

int main(int argc, char* argv[]) {
#if HAVE_STDIO_H
    printf("have stdio.h\n");
#endif
    return 0;
}