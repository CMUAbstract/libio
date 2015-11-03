#ifndef LIBIO_LOG_H
#define LIBIO_LOG_H

/* Configuration:
 *   * Verbosity level: VERBOSE[<level>], where <level> is a digit 2 or above
 *
 * Usage:
 *   * LOG<level>()
 *   * BLOCK_LOG_BEGIN(),BLOCK_LOG(),BLOCK_LOG_END()
 */

#include "printf.h"

#if defined(VERBOSE) || defined(VERBOSE2)

#define BLOCK_LOG_BEGIN() BLOCK_PRINTF_BEGIN()
#define BLOCK_LOG(...)    BLOCK_PRINTF(__VA_ARGS__)
#define BLOCK_LOG_END()   BLOCK_PRINTF_END()

#ifdef VERBOSE
#define LOG PRINTF
#else
#define LOG(...)
#endif

#ifdef VERBOSE2
#define LOG2 PRINTF
#else // !VERBOSE2
#define LOG2(...)
#endif // !VERBOSE2

#else // !VERBOSE*

#define LOG(...)
#define LOG2(...)

#define BLOCK_LOG_BEGIN()
#define BLOCK_LOG(...)
#define BLOCK_LOG_END()

#endif // !VERBOSE*

#endif // LIBIO_LOG_H
