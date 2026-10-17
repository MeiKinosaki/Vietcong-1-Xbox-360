CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic -O2
BUILD_DIR ?= build
CORE = src/core/port_state.c
TEST = tests/test_port_state.c
TEST_BIN = $(BUILD_DIR)/test_port_state

.PHONY: all test clean
all: test

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TEST_BIN): $(CORE) $(TEST) src/core/port_state.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc/core $(CORE) $(TEST) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -rf $(BUILD_DIR)
