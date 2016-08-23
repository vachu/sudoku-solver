#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <utility>

#include "CSudokuSolver.h"

int main(void) {
    CSudokuGrid solver;
    
    std::cout << solver.toString(false);
    return 0;
}
