#ifndef I2C_H
#define I2C_H

#include <stdint.h>

extern volatile uint32_t i2c_addr __attribute__((section(".i2c_addr_vec")));
extern volatile uint32_t i2c_data __attribute__((section(".i2c_data_vec")));
extern volatile uint32_t i2c_status __attribute__((section(".i2c_status_vec")));

#define I2C_LEN_1 0x0
#define I2C_LEN_2 0x1
#define I2C_LEN_3 0x2
#define I2C_LEN_4 0x3

#define I2C_READ 0x4
#define I2C_WRITE 0x0
#define I2C_RST 0x8

#define I2C_ERR(status)	((status & 0x40) == 0x40)
#define I2C_FINISH(status) ((status & 0x80) == 0x80)

#define I2C_CMD_READ 0x0
#define I2C_CMD_WRITE 0x1
#define I2C_CMD_FLASH 0x2
#define I2C_CMD_PRINT 0x3

#endif