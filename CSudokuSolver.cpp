/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CSudokuSolver.cpp
 * Author: vatsan
 * 
 * Created on 23 August, 2016, 7:01 PM
 */

#include <vector>
#include <sstream>
#include <iomanip>

#include "CSudokuSolver.h"

CSudokuGrid::CSudokuGrid() {
    for (int i = 0; i < 9; i++) {
        std::vector<int*> r, c;
        for (int j = 0; j < 9; j++) {
            g99[i][j] = 0;
            r.push_back(&g99[i][j]);
            c.push_back(&g99[j][i]);
        }
        row.push_back(std::move(r));
        col.push_back(std::move(c));
    }
}

CSudokuGrid::~CSudokuGrid() {
}

std::string CSudokuGrid::toString(bool isCSVFormat) {
    std::stringstream ss;
    for (int i = 0; i < 9; i++) {
        if (!isCSVFormat && i > 0 && i % 3 == 0)
            ss << "---------+---------+---------" << std::endl;

        for (int j = 0; j < 9; j++) {
            if (!isCSVFormat && j > 0 && j % 3 == 0)
                ss << "|";

            ss << std::setw(2) << g99[i][j]
                << (isCSVFormat ? (j == 8 ? "" : ",") : " ");
        }
        ss << std::endl;
    }
    return ss.str();
}

