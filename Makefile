LIB = libio

DEPS = libfemto libspike

include ../../Makefile.config
ifeq ($(LIBIO_BACKEND),spike)
OBJECTS = uart_spike_htif.o
else ifeq ($(LIBIO_BACKEND),manic)
OBJECTS = uart_manic_i2c.o i2c.o gpio.o
else ifeq ($(LIBIO_BACKEND),qemu)
OBJECTS = uart_qemu_sifive.o
else ifeq ($(LIBIO_BACKEND),arty)
OBJECTS = uart_coreip_e2_arty.o 
else ifeq ($(LIBIO_BACKEND),virt)
OBJECTS = uart_virt_16550.o
endif # LIBIO_BACKEND

override SRC_ROOT = ../../src

override CFLAGS += -I $(SRC_ROOT)/include/$(LIB)

include $(MAKER_ROOT)/Makefile.$(TOOLCHAIN)
