#include <stdbool.h>

#include <libfemto/femto.h>

#include "console.h"
#include "i2c.h"

#define I2C_UART_DEVICE_ADDR 0xad

void init_uart() {}

int putchar(int ch) {
#ifdef SILICON
	delay(10000);
#endif
	i2c_addr = I2C_UART_DEVICE_ADDR;
	i2c_data = I2C_CMD_PRINT;
	i2c_status = I2C_LEN_1 | I2C_WRITE;
	while(!i2c_status);
#ifdef SILICON
	delay(5000);
#endif
	i2c_data = ch & 0xff;
	i2c_status = I2C_LEN_1 | I2C_WRITE;
	while(!i2c_status);	
	return ch & 0xff;
}

int getchar() { return 0; } // Not implemented
