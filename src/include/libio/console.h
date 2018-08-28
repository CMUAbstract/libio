#ifndef LIBIO_CONSOLE_H
#define LIBIO_CONSOLE_H

void init();
int putchar(int);
int getchar();
void poweroff(void) __attribute__((noreturn));

#endif // LIBIO_CONSOLE_H
