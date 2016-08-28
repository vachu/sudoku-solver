#
# NOTE: This may not be the most ideal Makefile.  Simplicity was overwhelmingly
# preferred over everthing else.
#
TARGET_MAIN = sudoku-solver
TARGET_TEST = Test
TARGETS = $(TARGET_MAIN) $(TARGET_TEST)
SRCS = main.cpp CSudokuSolver.cpp CSudokuSolver.h
TEST_SRCS = UnitTest.cpp CSudokuSolver.cpp CSudokuSolver.h

FLAGS  += -std=c++14
ifndef RELEASE
	FLAGS += -g
else
	FLAGS += -O3
endif

.PHONY: all clean

all: $(TARGETS)

$(TARGET_MAIN): $(SRCS)
	g++ $(FLAGS) $(SRCS) -o $(TARGET_MAIN)

$(TARGET_TEST): $(TEST_SRCS)
	g++ $(FLAGS) $(TEST_SRCS) -o $(TARGET_TEST)

clean:
	@rm -f $(TARGETS)
