TARGET = sudoku-solver
SRCS = main.cpp CSudokuSolver.cpp

ifndef RELEASE
	CFLAGS += -g
	LDFLAGS += -g
else
	CFLAGS += -O3
	LDFLAGS += -O3
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	g++ -std=c++14 $(CFLAGS) $(SRCS) -o $(TARGET)

CSudokuSolver.cpp: CSudokuSolver.h
	@touch $@

clean:
	@rm -f $(TARGET) *.o
