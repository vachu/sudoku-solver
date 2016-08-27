#include <iostream>
#include <sstream>

#include "CSudokuSolver.h"

int main(void) {
    try {
        std::stringstream ss;
        ss      << "1, 1, 1, 2, 2, 2, 3, 3, 3,"
                << "4, 4, 4, 5, 5, 5, 6, 6, 6,"
                << "7, 7, 7, 8, 8, 8, 9, 9, 9,"
                << "9, 9, 9, 8, 8, 8, 7, 7, 7,"
                << "6, 6, 6, 5, 5, 5, 4, 4, 4,"
                << "3, 3, 3, 2, 2, 2, 1, 1, 1,"
                << "5, 5, 5, 6, 6, 6, 7, 7, 7,"
                << "8, 8, 8, 9, 9, 9, 1, 1, 1,"
                << "2, 2, 2, 3, 3, 3, 4, 4, 4";

        CSudokuGrid solver(ss);
        solver.solve();
        std::cout << solver.toString();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown Exception";
        return 2;
    }
    return 0;
}
