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

/*
 * 9x9 full Sudoku-Grid: Cell --> row,col
 * 
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
 * 
 * g33 --> mini / sub-grids
 * 
            |             |
   g33[0]   |    g33[1]   |    g33[2]
            |             |
------------+-------------+-------------
            |             |
   g33[3]   |    g33[4]   |    g33[5]
            |             |
------------+-------------+-------------
            |             |
   g33[6]   |    g33[7]   |    g33[8]
            |             |
 */
#include <sstream>
#include <iomanip>
#include <iostream>

#include "CSudokuSolver.h"

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

CSudokuGrid::CSudokuGrid(std::istream &istr) : CSudokuGrid() {
    loadSudokuGrid(istr);
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

void CSudokuGrid::loadSudokuGrid(std::istream& istr)
    throw(std::ios_base::failure, std::range_error)
{
    if (!istr.good()) throw std::ios_base::failure(
                                std::string(__FUNCTION__)+": Bad input stream"
                            );
    int n = 0;
    for (std::string line; std::getline(istr, line);) {
        std::stringstream csvLineStream(line);
        for (std::string cell; std::getline(csvLineStream, cell, ','); n++) {
            auto cellValue = std::stoi(cell);
            if (cellValue < 1 || cellValue > 9)
                throw std::range_error(
                                std::string(__FUNCTION__)+": Illegal cell value"
                            );
            auto i = n / 9; auto j = n % 9;
            g99[i][j] = cellValue;
        }
    }
    if (n != 81) throw std::range_error(
                            std::string(__FUNCTION__)+": Illegal cell count"
                        );
}

void CSudokuGrid::solve() {
    /*
     * while (getNextZeroValueCell())
     *      for i in 1..9
     *          cellValue <- i
     *          if isGridOk() && solve()
     *              break
     *      end-for
     */
    
}

// Returns 'true' if the values in the 9x9 Sudoku grid conforms to Sudoku Rule;
// 'false' otherwise.  If 'ignoreZero' is true, ZERO values in cells are ignored
bool CSudokuGrid::isGridOk(bool ignoreZero) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int g33idx = (i/3)*3 + (j/3);
            int g33_i  = (i*3)%9 + j%3;
            
            auto cellMiniGrid = g33[g33idx];
            auto cellRow      = row[i];
            auto cellCol      = col[j];
            auto val          = g99[i][j];

            if (isInVector(cellRow, val, j, ignoreZero) ||
                isInVector(cellCol, val, i, ignoreZero) ||
                isInVector(cellMiniGrid, val, g33_i, ignoreZero) )
            {
                return false;
            }
        }
    }
    return true;
}

bool CSudokuGrid::isInVector(
                    const std::vector<int*>& v,
                    int val,
                    int skipIndex,
                    bool ignoreZero
                )
{
    for (int i = 0; i < v.size(); i++) {
        if (i == skipIndex) continue;
        if (ignoreZero && *v[i] == 0) continue;
        
        if (val == *v[i]) return true;
    }
    return false;
}
