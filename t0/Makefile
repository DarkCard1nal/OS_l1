CXX = g++
CXXFLAGS = -Wall -g
BUILD_DIR = bin/build
SRC = main.cpp
TARGET = $(BUILD_DIR)/main
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)
TEST_SRC = test.cpp
TEST_TARGET = $(BUILD_DIR)/test
TEST_OBJ = $(TEST_SRC:%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

release: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(BUILD_DIR) $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

$(TEST_OBJ): $(TEST_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET)