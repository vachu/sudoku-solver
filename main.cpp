#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <utility>

typedef int * PINT;

int g99[][9] = {
    { 0,  1,  2,  3,  4,  5,  6,  7,  8},
    {10, 11, 12, 13, 14, 15, 16, 17, 18},
    {20, 21, 22, 23, 24, 25, 26, 27, 28},
    {30, 31, 32, 33, 34, 35, 36, 37, 38},
    {40, 41, 42, 43, 44, 45, 46, 47, 48},
    {50, 51, 52, 53, 54, 55, 56, 57, 58},
    {60, 61, 62, 63, 64, 65, 66, 67, 68},
    {70, 71, 72, 73, 74, 75, 76, 77, 78},
    {80, 81, 82, 83, 84, 85, 86, 87, 88},
};

std::vector<std::vector<int*>> col;
std::vector<std::vector<int*>> row;

int main(void) {
    for (int i = 0; i < 9; i++) {
        std::vector<int*> r, c;
        for (int j = 0; j < 9; j++) {
            r.push_back(&g99[i][j]);
            c.push_back(&g99[j][i]);
        }
        row.push_back(std::move(r));
        col.push_back(std::move(c));
    }

    for (int i = 0; i < 9; i++) {
        for (auto ptrCell: col[i]) {
            std::cout << std::setw(3) << *ptrCell;
        }
        std::cout << std::endl;
    }
    return 0;
}
