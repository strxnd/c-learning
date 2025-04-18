# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Files
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
BIN = $(BIN_DIR)/prime-numbers-array-challenge

# Default rule
all: $(BIN)

# Linking
$(BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $(BIN)

# Compiling
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Install rule
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

install: all
	install -d $(BINDIR)
	install -m 755 $(BIN) $(BINDIR)

# Uninstall rule
uninstall:
	rm -f $(BINDIR)/$(notdir $(BIN))

.PHONY: all clean install uninstall
