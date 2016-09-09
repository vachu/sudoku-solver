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
        std::stringstream ss;
        ss      << "0, 0, 0, 6, 0, 9, 0, 0, 0,"
                << "0, 0, 7, 0, 0, 0, 1, 0, 0,"
                << "3, 0, 0, 0, 1, 0, 0, 0, 2,"
                << "0, 0, 1, 0, 0, 0, 4, 0, 0,"
                << "0, 5, 0, 0, 9, 0, 0, 8, 0,"
                << "0, 7, 0, 0, 6, 0, 0, 5, 0,"
                << "1, 4, 0, 0, 8, 0, 0, 6, 7,"
                << "0, 6, 8, 0, 5, 0, 9, 2, 0,"
                << "2, 0, 0, 0, 0, 0, 0, 0, 8,";
        CSudokuGrid solver(ss);
        std::cout << "Incomplete Grid:" << std::endl << solver.toString();
        solver.solve(); //std::cout << std::endl;
        std::cout << "Completed Grid:" << std::endl << solver.toString();
        std::cout << "isGridOk()=" << solver.isGridOk(false) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown Exception";
        return 3;
    }
    return 0;
}

