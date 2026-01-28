#pragma once
#include<vector>
#include<raylib.h>
#include<iostream>
using namespace std;

class Grid{
    private:
    int num_rows;
    int num_cols;
    int cell_size;// in pixels
    vector<Color> colors;
    bool IsRowFull(int row);
    void clearRow(int row);
    // vector<Color> GetCellColors();

    public:
    Grid();
    int grid[20][10];
    void initialize();
    void print();
    void Draw();
    bool IsCellOutside(int row,int cols);
    bool IsCellEmpty(int row, int cols);
    void MoveRowDown(int row,int numRows);
    int clearFullRows();

};