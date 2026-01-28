#include "grid.h"
#include<iostream>
#include "colors.h"
using namespace std; 

Grid::Grid()
{
    num_cols=10;
    num_rows=20;
    cell_size=30;
    initialize();
    colors=GetCellColors();//
}
//intializing the grid array to zero
void Grid:: initialize()
{
    for(int row=0;row<num_rows;row++)
    {
        for(int cols=0;cols<num_cols;cols++)
        {
            grid[row][cols]=0;
        }
    }
}
//printng the grid array

void Grid::print(){
    for(int row=0;row<num_rows;row++)
    {
        for(int cols=0;cols<num_cols;cols++)

        {
            cout<<grid[row][cols]<<" ";
        }
        cout<<endl;
    }
}
// //to create colors for cell and return
// vector <Color> Grid::GetCellColors()
// {
//     Color darkGrey={26,31,48,255};
//     Color green={47,230,23,255};
//     Color red={232,18,18,255};
//     Color orange={226,116,4,255};
//     Color yellow={237,234,4,255};
//     Color purple={116,0,247,255};
//     Color cyan={21,204,209,255};
//     Color blue={13,64,216,255 };
//     return {darkGrey,green,red,orange,yellow,purple,cyan,blue};
// }

//--we included the color header file so we have all the color we needed in that file

//drawing the grid
//grey color if cell contain value 0
//green color if cell contains value 1....
void Grid::Draw()
{
    for(int row=0;row<num_rows;row++)
    {
        for(int cols =0; cols<num_cols;cols++)
        {
            int cell_value=grid[row][cols];
            DrawRectangle(cols*cell_size+11,row*cell_size+11,cell_size-1,cell_size-1,colors[cell_value]);//raylib to draw the rectangle in grid
        }
    }
}

bool Grid::IsCellOutside(int row, int cols)
{
    if(row >=0 && row < num_rows && cols >=0 && cols < num_cols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int cols)
{
    if(grid[row][cols]==0)
    {
        return true;
    }
    return false;
}

bool Grid::IsRowFull(int row)
{
    for(int cols=0; cols<num_cols; cols++)
    {
        if(grid[row][cols]==0)
        {
            return false;
        }
        
    }
    return true;
}

void Grid::clearRow(int row)
{
    for(int cols=0;cols<num_cols;cols++)
    {
        grid[row][cols]=0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int cols=0;cols<num_cols;cols++)
    {
        grid[row+numRows][cols]= grid[row][cols];
        grid[row][cols] = 0;
    }
}

int Grid::clearFullRows()
{
    int completed=0;
    for(int row= num_rows-1;row>=0;row--)
    {
        if(IsRowFull(row))
        {
            clearRow(row);
            completed++;
        }
        else if( completed >0 )
        {
            MoveRowDown(row,completed);
        }
    }
    return completed;
}
