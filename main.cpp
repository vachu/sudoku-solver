#include <iostream>
#include <sstream>

#include "CSudokuSolver.h"

int main(void) {
    try {
        CSudokuGrid solver;
        std::cout << "Incomplete Grid:" << std::endl << solver.toString();
        std::cout << "Completed Grid:" << std::endl << solver.toString();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown Exception";
        return 2;
    }
    return 0;
}
