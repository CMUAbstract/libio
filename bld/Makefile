LIB = libio

OBJECTS = \
	console_$(LIBIO_BACKEND).o \

ifeq ($(LIBIO_BACKEND),)
$(error No libio backend defined: LIBIO_BACKEND)
endif # LIBIO_BACKEND

override SRC_ROOT = ../../src
