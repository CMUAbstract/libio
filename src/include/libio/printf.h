#ifndef LIBIO_PRINTF_H
#define LIBIO_PRINTF_H

/* Configuration:
 *
 *  Console lib selection:
 *
 *   * CONFIG_LIBEDB_PRINTF_<type>
 *       where <type> specifies the implementation for the PRINTF macro (the
 *       default) is either EIF or BARE
 *
 *   * CONFIG_LIBMSPCONSOLE_PRINTF
 *
 * Usage:
 *
 *   * use the PRINTF and BLOCK_PRINTF_BEGIN,BLOCK_PRINTF,BLOCK_PRINTF_END macros
 *   * (uncommon) use EIF_PRINTF or BARE_PRINTF specifically
 */

#if defined(CONFIG_LIBEDB_PRINTF_EIF) || defined(CONFIG_LIBEDB_PRINTF_BARE)

// The multi-statement printf, is...
#define BLOCK_PRINTF_BEGIN() ENERGY_GUARD_BEGIN()
#define BLOCK_PRINTF(...) BARE_PRINTF(__VA_ARGS__)
#define BLOCK_PRINTF_END() ENERGY_GUARD_END()

// By default, printf is...
#if defined(CONFIG_LIBEDB_PRINTF_EIF)
#define PRINTF(...) EIF_PRINTF(__VA_ARGS__)
#elif defined(CONFIG_LIBEDB_PRINTF_BARE)
#define PRINTF(...) BARE_PRINTF(__VA_ARGS__)
#endif

#elif defined(CONFIG_LIBMSPCONSOLE_PRINTF)

// All special printfs fall back to the regular printf
#define BLOCK_PRINTF_BEGIN()
#define BLOCK_PRINTF(...) printf(__VA_ARGS__)
#define BLOCK_PRINTF_END()

#define EIF_PRINTF(...)  printf(__VA_ARGS__)
#define BARE_PRINTF(...) printf(__VA_ARGS__)

#else // no printf

// All printfs fall back to nop
#define BLOCK_PRINTF_BEGIN()
#define BLOCK_PRINTF(...)
#define BLOCK_PRINTF_END()

#define PRINTF(...)

#define EIF_PRINTF(...)
#define BARE_PRINTF(...)

#endif // no printf

#endif // LIBIO_PRINTF_H
