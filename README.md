Easy "clone and go" repository for a libopencm3 based project.

# Instructions
 1. git clone https://github.com/libopencm3/libopencm3-template.git your-project
 2. cd your-project
 3. git submodule update --init # (Only needed once)
 4. make -C libopencm3 # (Only needed once)
 5. make -C src

# Directories
* out contains linked binary (when compile and link succeeded)
* src contains src code

# Template
This template has a blinky start using systick. USART3 is enabled, for trace output using printf

# Makefile
Add the next line to enable printf float capabilities:
`LDFLAGS += -u _printf_float`
Skip it and make your own float output function if you need the space.

## You
You should replace this with your _own_ README if you are using this
as a template.
