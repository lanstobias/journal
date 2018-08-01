# Modified from: https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/

EXE := journal
 
# Compiler options
CC := g++
CFLAGS := -g -Wall -Wextra -Weffc++

# Directories
SRC_DIR := src
BUILD_DIR := build
TARGET := bin/$(EXE)
 
# Extensions
SRC_EXT := cpp

# Files
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))

# Dependencies
LIB := 
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_DIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILD_DIR) $(TARGET)"; $(RM) -r $(BUILD_DIR) $(TARGET)

# Tests
test:
	$(CC) tests/test.$(SRC_EXT) $(INC) $(LIB) -o bin/test

# Spikes
spikes:
	$(CC) $(CFLAGS) spikes/spike.$(SRC_EXT) $(INC) $(LIB) -o bin/spike

.PHONY: clean