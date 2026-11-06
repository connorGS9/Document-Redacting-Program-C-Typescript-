# ---- settings ------------------------------------------------------------
CC      := gcc
CFLAGS  := -std=c11 -g -O0 -Wall -Wextra -Wpedantic \
           -fsanitize=address,undefined -fno-omit-frame-pointer
LDFLAGS := -fsanitize=address,undefined

SRC_DIR := src
BUILD   := build
SRCS    := $(wildcard $(SRC_DIR)/*.c)
OBJS    := $(patsubst $(SRC_DIR)/%.c,$(BUILD)/%.o,$(SRCS))
DEPS    := $(OBJS:.o=.d)
BIN     := $(BUILD)/scan

# ---- targets -------------------------------------------------------------
.PHONY: all clean

all: $(BIN)

# link: all object files -> one program
$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# compile: each src/x.c -> build/x.o (and build/x.d, a list of headers it uses)
$(BUILD)/%.o: $(SRC_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

# rebuild a .c file automatically when a header it includes changes
-include $(DEPS)