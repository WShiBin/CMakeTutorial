// #cmakedefine语法
/* #undef LOG_DEBUG_ENABLE */
// 不存在: /* #undef LOG_DEBUG_ENABLE */
// 存在: // #define LOG_DEBUG_ENABLE

/* #undef LOG_DEBUG_ENABLE */
// 不存在: /* #undef LOG_DEBUG_ENABLE */
// 存在: #define LOG_DEBUG_ENABLE ON

// #cmakedefine01语法
// #define LOG_DEBUG_ENABLE 0
// 不存在: #define LOG_DEBUG_ENABLE 0
// 存在: #define LOG_DEBUG_ENABLE 1
