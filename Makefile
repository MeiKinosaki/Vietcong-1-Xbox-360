CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic -O2
BUILD_DIR ?= build
CORE = src/core/port_state.c
INPUT = src/platform/controller_input.c
TEST_STATE = tests/test_port_state.c
TEST_INPUT = tests/test_controller_input.c
TEST_STATE_BIN = $(BUILD_DIR)/test_port_state
TEST_INPUT_BIN = $(BUILD_DIR)/test_controller_input

.PHONY: all test clean
all: test

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TEST_STATE_BIN): $(CORE) $(TEST_STATE) src/core/port_state.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc/core $(CORE) $(TEST_STATE) -o $@

$(TEST_INPUT_BIN): $(INPUT) $(TEST_INPUT) src/platform/controller_input.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc/platform $(INPUT) $(TEST_INPUT) -o $@

test: $(TEST_STATE_BIN) $(TEST_INPUT_BIN)
	./$(TEST_STATE_BIN)
	./$(TEST_INPUT_BIN)

clean:
	rm -rf $(BUILD_DIR)
