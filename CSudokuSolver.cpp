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
#include <iostream>

#include "CSudokuSolver.h"
/*
0,0 0,1 0,2 | 0,3 0,4 0,5 | 0,6 0,7 0,8
1,0 1,1 1,2 | 1,3 1,4 1,5 | 1,6 1,7 1,8
2,0 2,1 2,2 | 2,3 2,4 2,5 | 2,6 2,7 2,8
------------+-------------+-------------
3,0 3,1 3,2 | 3,3 3,4 3,5 | 3,6 3,7 3,8
4,0 4,1 4,2 | 4,3 4,4 4,5 | 4,6 4,7 4,8
5,0 5,1 5,2 | 5,3 5,4 5,5 | 5,6 5,7 5,8
------------+-------------+-------------
6,0 6,1 6,2 | 6,3 6,4 6,5 | 6,6 6,7 6,8
7,0 7,1 7,2 | 7,3 7,4 7,5 | 7,6 7,7 7,8
8,0 8,1 8,2 | 8,3 8,4 8,5 | 8,6 8,7 8,8
 * g33[i] ==>> (i/3)*3 + (j/3)
 */

CSudokuGrid::CSudokuGrid() {
    for (int i = 0; i < 9; i++) g33.push_back(std::vector<int*>());

    for (int i = 0; i < 9; i++) {
        std::vector<int*> r, c;
        for (int j = 0; j < 9; j++) {
            g99[i][j] = 0;
            r.push_back(&g99[i][j]);
            c.push_back(&g99[j][i]);
            
            int g33idx = (i/3)*3 + (j/3);
            g33[g33idx].push_back(&g99[i][j]);
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

