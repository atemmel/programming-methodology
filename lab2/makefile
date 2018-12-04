SRC_DIR := .
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

build: $(SRC_FILES)
	g++ $^

run: build
	./a.out
