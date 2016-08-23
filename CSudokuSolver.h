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
    
    std::string toString(bool isCSVformat = true);
private:
    int g99[9][9];
    std::vector<std::vector<int*>> col;
    std::vector<std::vector<int*>> row;
};

#endif /* CSUDOKUSOLVER_H */

