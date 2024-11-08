CXX = g++-14
CXXFLAGS = -Wall -std=c++11 -fPIC

LDFLAGS = -shared

# Пути
BUILD_DIR = bin/build
LIB_DIR = $(BUILD_DIR)/lib
EXEC_DIR = $(BUILD_DIR)

# Имя библиотеки
LIBRARY_NAME = libarraylist.so

# Источник библиотеки
ARRAYLIST_SRC = ArrayList.cpp
ARRAYLIST_OBJ = $(BUILD_DIR)/ArrayList.o

# Источник теста
TEST_SRC = test.cpp

# Цели
all: $(LIB_DIR)/$(LIBRARY_NAME) $(EXEC_DIR)/test

release: $(LIB_DIR)/$(LIBRARY_NAME)

# Цель для сборки динамической библиотеки
$(LIB_DIR)/$(LIBRARY_NAME): $(ARRAYLIST_OBJ)
	@mkdir -p $(LIB_DIR)
	$(CXX) $(LDFLAGS) $(ARRAYLIST_OBJ) -o $(LIB_DIR)/$(LIBRARY_NAME)

# Цель для компиляции объектного файла библиотеки
$(ARRAYLIST_OBJ): $(ARRAYLIST_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(ARRAYLIST_SRC) -o $(ARRAYLIST_OBJ)

# Цель для компиляции теста с линковкой к библиотеке
$(EXEC_DIR)/test: $(TEST_SRC) $(LIB_DIR)/$(LIBRARY_NAME)
	@mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(EXEC_DIR)/test -L$(LIB_DIR) -larraylist

# Очистка
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all release clean