CXX = g++-14
CXXFLAGS = -Wall -std=c++11 -fPIC

LDFLAGS = -shared

BUILD_DIR = bin/build
LIB_DIR = $(BUILD_DIR)/lib
EXEC_DIR = $(BUILD_DIR)

LIBRARY_NAME = libarraylist.so
LIBRARY_NAME_STATIC = libarraylist.a

ARRAYLIST_SRC = ArrayList.cpp
ARRAYLIST_OBJ = $(BUILD_DIR)/ArrayList.o

TEST_SRC = test.cpp

all: $(LIB_DIR)/$(LIBRARY_NAME) $(EXEC_DIR)/test $(EXEC_DIR)/test_static

release: $(LIB_DIR)/$(LIBRARY_NAME)

$(LIB_DIR)/$(LIBRARY_NAME): $(ARRAYLIST_OBJ)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(LDFLAGS) $(ARRAYLIST_OBJ) -o $(LIB_DIR)/$(LIBRARY_NAME)
	ar rcs $(LIB_DIR)/$(LIBRARY_NAME_STATIC) $(ARRAYLIST_OBJ)

$(ARRAYLIST_OBJ): $(ARRAYLIST_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(ARRAYLIST_SRC) -o $(ARRAYLIST_OBJ)

$(EXEC_DIR)/test: $(TEST_SRC) $(LIB_DIR)/$(LIBRARY_NAME)
	@mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(EXEC_DIR)/test -L$(LIB_DIR) -larraylist

$(EXEC_DIR)/test_static: $(TEST_SRC) $(LIB_DIR)/$(LIBRARY_NAME_STATIC)
	@mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(EXEC_DIR)/test_static -L$(LIB_DIR) -larraylist

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all release clean