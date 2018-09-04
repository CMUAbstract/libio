// See LICENSE for license details.

#include <libfemto/atomic.h>
#include <libfemto/encoding.h>
#include <libspike/abi.h>

#include "console.h"

static spinlock_t htif_lock = SPINLOCK_INIT;

int getchar() {
  spinlock_lock(&htif_lock);
    uint64_t fh = recv();
    if(FROMHOST_CMD(fh) != 0) {
      return -1;
    }
    int ch = 1 + (uint8_t)FROMHOST_DATA(fh);
    if (ch >= 0) {
      send(1, 0, 0);
    }
  spinlock_unlock(&htif_lock);

  return ch - 1;
}

int putchar(int ch) {
  spinlock_lock(&htif_lock);
    send(1, 1, ch & 0xff);
  spinlock_unlock(&htif_lock);
  return ch & 0xff;
}

void init_uart() {}
