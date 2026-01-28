#pragma once
#include <vector>
#include<map>
#include "position.h"
#include<iostream>
#include "colors.h"

using namespace std;
class Block{
    public:
        Block();
        int id;
        void Draw(int offsetx,int offsety);
        void Move(int row, int cols);
        vector<Position> GetCellPositions();
        
        map<int,vector<Position>>cells;
        void Rotate();
        void UndoRotation();

    private:
    int cell_size;
    int rotationState;
    vector<Color>colors;
    int row_offset;
    int cols_offset;
};