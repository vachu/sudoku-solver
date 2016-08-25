/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CSudokuSolver.h
 * Author: vatsan
 *
 * Created on 23 August, 2016, 7:01 PM
 */
#include <string>

#ifndef CSUDOKUSOLVER_H
#define CSUDOKUSOLVER_H

class CSudokuGrid {
public:
    CSudokuGrid();
    CSudokuGrid(const CSudokuGrid& orig) = delete;
    virtual ~CSudokuGrid();
    
    std::string toString(bool isCSVformat = false);
private:
    int g99[9][9]; // 9x9 full sudoku grid
    std::vector<std::vector<int*>> col;
    std::vector<std::vector<int*>> row;
    std::vector<std::vector<int*>> g33; // 3x3 grid
};

#endif /* CSUDOKUSOLVER_H */

