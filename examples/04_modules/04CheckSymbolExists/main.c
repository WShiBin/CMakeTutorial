#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char* argv[]) {
#if HAVE_FOPEN
    FILE* file = fopen("CMakeLists.txt", "r");
#if HAVE_SEEK_SET
    fseek(file, 0, SEEK_SET);
#endif
    fclose(file);
#endif

    return 0;
}