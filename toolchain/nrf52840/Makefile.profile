# set default port depending on operating system
PORT_LINUX ?= /dev/ttyACM0
PORT_DARWIN ?= $(firstword $(sort $(wildcard /dev/tty.usbmodem*)))

# define jlink as default programmer, but overridable
PROGRAMMER ?= jlink

ifeq (jlink,$(PROGRAMMER))
  # setup JLink for flashing
  export JLINK_DEVICE := nrf52
  export FLASH_ADDR := 0x1f000
endif

# set default port depending on operating system
OS := $(shell uname)
ifeq ($(OS),Linux)
  PORT ?= $(PORT_LINUX)
else ifeq ($(OS),Darwin)
  PORT ?= $(PORT_DARWIN)
endif
ifeq ($(PORT),)
  $(info Warning: no PORT set!)
endif

export PORT
export BAUD ?= 115200

NDNLITE_TERMINAL ?= pyterm
ifeq ($(NDNLITE_TERMINAL),pyterm)
    export TERMPROG  ?= ../../third-party/pyterm/pyterm
    export TERMFLAGS ?= -p "$(PORT)" -b "$(BAUD)"
else ifeq ($(NDNLITE_TERMINAL),picocom)
    export TERMPROG  ?= picocom
    export TERMFLAGS ?= --nolock --imap lfcrlf --echo --baud "$(BAUD)" "$(PORT)"
endif
