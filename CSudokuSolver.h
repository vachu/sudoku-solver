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
#include <vector>
#include <istream>
#include <exception>

#ifndef CSUDOKUSOLVER_H
#define CSUDOKUSOLVER_H

#ifdef UNIT_TEST
    #define PRIVATE public
#else
    #define PRIVATE private
#endif

class CSudokuGrid {
public:
    CSudokuGrid();
    explicit CSudokuGrid(std::istream &);
    CSudokuGrid(const CSudokuGrid& orig) = delete;
    
    virtual ~CSudokuGrid();

    void solve();
    std::string toString(bool isCSVformat = false);
    
PRIVATE:
    int g99[9][9]; // 9x9 full sudoku grid
    /*
     * The following 2D vectors wherein each of the elements in the contained
     * vector points to cell in the above 9x9 full sudoku grid
     */
    std::vector<std::vector<int*> > col; // top->bottom column in 9x9 grid
    std::vector<std::vector<int*> > row; // left-right row in 9x9 grid
    std::vector<std::vector<int*> > g33; // 3x3 mini/sub-grid

    void loadSudokuGrid(std::istream &istr)
        throw(std::ios_base::failure, std::range_error);
    bool isGridOk(bool ignoreZero = true);
    bool isInVector(
            const std::vector<int*>& v,
            int val,
            int skipIndex, // skip comparing val with v[skipIndex]
            bool ignoreZero = true // if 'true', skip if *v[skipIndex] == 0
        );
};

#endif /* CSUDOKUSOLVER_H */

