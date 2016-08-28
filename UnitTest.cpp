/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UnitTest.cpp
 * Author: vatsan
 *
 * Created on 28 August, 2016, 11:37 AM
 */

#include <iostream>
#include <sstream>

#define UNIT_TEST
#include "CSudokuSolver.h"

int main(int argc, char** argv) {
    try {
        std::cout << argv[0] << std::endl;
        std::stringstream ss;
        ss      << "1, 1, 1, 2, 2, 2, 3, 3, 3,"
                << "4, 4, 4, 5, 5, 5, 6, 6, 6,"
                << "7, 7, 7, 8, 8, 8, 9, 9, 9,"
                << "9, 9, 9, 8, 8, 8, 7, 7, 7,"
                << "6, 6, 6, 5, 5, 5, 4, 4, 4,"
                << "3, 3, 3, 2, 2, 2, 1, 1, 1,"
                << "5, 5, 5, 6, 6, 6, 7, 7, 7,"
                << "7, 7, 7, 9, 9, 9, 1, 1, 1,"
                << "2, 2, 2, 3, 3, 3, 4, 4, 4";
        CSudokuGrid solver;
        std::cout << solver.toString();
        
        solver.g99[8][8] = 0;
        std::cout << solver.isGridOk() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown Exception";
        return 2;
    }
    return 0;
}

