#include <iostream>
#include <fstream>

#include "CSudokuSolver.h"

void solveSudokuGrid(std::istream& inp) {
    try {
        CSudokuGrid grid(inp);
        std::cout << "Incomplete Grid:" << std::endl << grid.toString();
        if (grid.solve())
            std::cout << "Completed Grid:" << std::endl << grid.toString();
        else
            std::cerr << "Could not solve Grid" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Exception";
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Expecting CSV grid from STDIN:" << std::endl;
        solveSudokuGrid(std::cin);
    } else {
        if (argc == 2) {
            std::string arg(argv[1]);
            if (arg == "-h" || arg == "--help") {
                std::cerr << "TODO: to print help" << std::endl;
                return 1;
            }
        }
        
        for (int i = 1; i < argc; i++) {
            std::cout << "==== " << argv[i] << " ====" << std::endl;
            std::ifstream inp(argv[i]);
            solveSudokuGrid(inp);
        }
    }
    return 0;
}
