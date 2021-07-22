#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

int main(int argc, char* argv[]) {
    int ret = add(10, 20);
    printf("ret = %d\n", ret);
    return 0;
}