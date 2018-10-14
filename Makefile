CXX           := g++
LD            := g++
STANDARD      := -std=c++17

FLAGS         := -Wall -Wextra -Wwrite-strings -Wno-parentheses\
				 -Wno-deprecated -Wpedantic -Warray-bounds -Weffc++
CXXFLAGS      := $(FLAGS) $(STANDARD)
LDFLAGS       := $(FLAGS)

EXEC          := journal
SRC           := $(wildcard src/*.cpp)
OBJ           := $(SRC:src/%.cpp=build/%.o)
INC           := -I include

EXEC_TEST     := test
SRC_TEST      := $(wildcard test/*.cpp)
OBJ_TEST      := $(filter-out build/main.o, $(OBJ)) $(SRC_TEST:test/%.cpp=build/%.o)

.SUFFIXES:
.DELETE_ON_ERROR:

# --------------------------------------------------------------

.PHONY: all
all: bin/$(EXEC)

bin/$(EXEC): $(OBJ)
	@$(LD) $(LDFLAGS) $^ -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: test
test: bin/$(EXEC_TEST)

bin/$(EXEC_TEST): $(OBJ_TEST)
	@$(LD) $(LDFLAGS) $^ -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

build/%.o: src/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< $(INC) -o $@ && echo "[OK]  $@"

build/%.o: test/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< $(INC) -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: clean clear
clean clear:
	@rm -f bin/* && echo "[CL]  bin/"
	@rm -f build/* && echo "[CL]  build/"
