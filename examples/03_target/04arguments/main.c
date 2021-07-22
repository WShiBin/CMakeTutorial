#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "config.h"

// cmake -D LOG_DEBUG_ENABLE=ON 控制当前log级别
int main(int argc, char* argv[]) {
#ifdef LOG_DEBUG_ENABLE
    log_set_level(LOG_DEBUG);
#else
    log_set_level(LOG_WARN);
#endif

    log_trace("trace");
    log_debug("debug");
    log_info("info");
    log_warn("warn");
    log_error("error");
    return 0;
}