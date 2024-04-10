# Define the name of the final executable
EXEC = card_game

# Define all source files with a wildcard
SRC = $(wildcard *.c)

# Define build directory path (modify as needed)
BUILD_DIR = build

# Define all object file paths relative to build directory
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

# C compiler (modify if needed)
CC = gcc

# CFLAGS (compiler flags, modify as needed)
CFLAGS = -Wall -Wextra -Wunused-result -pedantic -O2 -lm -g

# Define how to compile a source file into an object file
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)  # Create build directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

# Define how to link all object files into the final executable
$(BUILD_DIR)/$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# The default rule to be called when running "make"
all: $(BUILD_DIR)/$(EXEC)

run: $(BUILD_DIR)/$(EXEC)
	./$(BUILD_DIR)/$(EXEC)

# Rule to clean up all object files
clean:
	rm -rf $(BUILD_DIR)  # Remove entire build directory