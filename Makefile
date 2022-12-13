CXX=clang++
INCLUDES=-Iincludes/ -Idata/ -Itests/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/test

bin/exec: ./entry/main.cpp ./src/parse.cpp ./src/routes.cpp ./src/util.cpp ./src/node.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/test: ./tests/tests.cpp ./src/parse.cpp ./src/routes.cpp ./src/util.cpp ./src/node.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

# obj/catch.o: tests/catch.cpp
# 	$(CXX) $(CXXFLAGS) -c $^ -o $@

# .DEFAULT_GOAL := tests
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*