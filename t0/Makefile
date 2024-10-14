CXX = g++-14
CXXFLAGS = -Wall -std=c++23
BUILD_DIR = bin/build

HEADERS = Point.hpp PointSimulator.hpp

SRC = main.cpp Point.cpp PointSimulator.cpp
TARGET = $(BUILD_DIR)/main
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

TEST_SRC = test.cpp Point.cpp PointSimulator.cpp
TEST_TARGET = $(BUILD_DIR)/test
TEST_OBJ = $(TEST_SRC:%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

release: $(BUILD_DIR) $(TARGET)

test: $(BUILD_DIR) $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJ)

$(BUILD_DIR)/%.o: %.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)
