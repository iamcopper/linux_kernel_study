CROSS_COMPILE ?=
CC := gcc
CFLAGS := -Wall -c -Werror
LDFLAGS :=

OBJS := main.o
OUT := main

ifeq ($(DEBUG),1)
CFLAGS+= -g
endif

$(OUT): $(OBJS)
	$(CROSS_COMPILE)$(CC) $^ -o $@ $(LDFLAGS)
%.o: %.c
	$(CROSS_COMPILE)$(CC) $^ -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OUT)
