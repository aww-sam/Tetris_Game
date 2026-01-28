#include "block.h"

Block :: Block()
{
    cell_size=30;
    rotationState=0;
    colors=GetCellColors();
    row_offset=0;
    cols_offset=0;
}

void Block::Draw(int offsetx, int offsety)
{
    std::vector<Position> tiles=GetCellPositions();//thies line retrives the vector of the positions for the current rotation state of the tetromino
    for(Position item:tiles)
    {
        DrawRectangle(item.cols*cell_size+offsetx,item.row*cell_size+offsety,cell_size-1,cell_size-1,colors[id]);
    }
}
//moving the block 
void Block::Move(int row,int cols)
{
    row_offset+=row;
    cols_offset+=cols;
}

//to calculate the current position after the offset
vector<Position> Block::GetCellPositions()
{
    vector<Position> tiles=cells[rotationState];
    vector<Position> movedTiles;
    for(Position item: tiles)

    {
        Position newposition=Position(item.row+row_offset,item.cols+cols_offset);
        movedTiles.push_back(newposition);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState ++;
    if(rotationState == (int)cells.size())
    {
        rotationState=0;
    }
}

void Block::UndoRotation()
{
    rotationState --;
    if(rotationState == -1)
    {
        rotationState=cells.size() -1;
    }
}
