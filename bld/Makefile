LIB = libio

OBJECTS = \
	empty.o \

ifneq ($(LIBIO_BACKEND),)
OBJECTS += \
	printf.o \
	console_$(LIBIO_BACKEND).o
endif

ifeq ($(LIBIO_BACKEND),hwuart)
override DEPS += libmsp
override CFLAGS += -DLIBIO_BACKEND_HWUART
else ifeq ($(LIBIO_BACKEND),swuart)
override DEPS += libmspsoftuart
override CFLAGS += -DLIBIO_BACKEND_SWUART
else ifeq ($(LIBIO_BACKEND),edb)
override DEPS += libedb
override CFLAGS += -DLIBIO_BACKEND_EDB
endif # LIBIO_BACKEND

override SRC_ROOT = ../../src
