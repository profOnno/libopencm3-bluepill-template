PROJECT = bluepill
#BUILD_DIR = bin see rules.mk below
TARGET_DIR = ../out

#SHARED_DIR = ../my-common-code
CFILES = main.c
#CFILES += ../my-common-code/api.c
#AFILES += ../my-common-code/api-asm.S

# TODO - you will need to edit these two lines!
DEVICE = stm32f103h6

#ARCH_FLAGS = -mthumb -mcpu=cortex-m3 -mfloat-abi=softfp --mfix-cortex-m3-ldrd

# You shouldn't have to edit anything below here.
#VPATH += $(SHARED_DIR)
#INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR = ../libopencm3

# enable floating point printf
LDFLAGS += -u _printf_float

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
