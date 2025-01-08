#Compiler and flags
CXX=g++
CXXFLAGS= -Wall -Wextra -std=c++17

# Directories
CATEGORY_FOLDER=containers/
SPECIFIC_FOLDER=vector/
SRC_DIR = tests/$(CATEGORY_FOLDER)$(SPECIFIC_FOLDER)
BUILD_DIR = build/$(CATEGORY_FOLDER)$(SPECIFIC_FOLDER)
INCLUDE_DIR = include/$(CATEGORY_FOLDER)$(SPECIFIC_FOLDER)

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Target executable
TARGET = program

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	@echo "Linking and producing the final application"
	$(CXX) $(OBJS) -o $@

# Compile each .cpp file into a .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
