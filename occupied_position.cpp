#include "block.h"
#include "position.h"
//this is created in order to decide the position of occupied cell for block inorder to draw it on the screen
class LBlock: public Block{
    public:
    LBlock(){
        id=1;
        cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)}; // 0 degrees
        cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)}; // 90 degrees
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)}; // 180 degrees
        cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)}; // 270 degrees

        Move(0,3);
    }
};

class JBlock:public Block{
    public:
    JBlock()
    {
        id=2;
        cells[0]={Position(0,0),Position(1,0),Position(1,1),Position(1,2)};//when the lblock is in 0 state the then the following cells are occupied
        cells[1]={Position(0,1),Position(0,2),Position(1,1),Position(2,1)};
        cells[2]={Position(1,0),Position(1,1),Position(1,2),Position(2,2)};
        cells[3]={Position(0,1),Position(1,1),Position(2,0),Position(2,1)};
        Move(0,3);
    }
};
class IBlock:public Block{
    public:
    IBlock()
    {
        id=3;
        cells[0]={Position(1,0),Position(1,1),Position(1,2),Position(1,3)};//when the lblock is in 0 state the then the following cells are occupied
        cells[1]={Position(0,2),Position(1,2),Position(2,2),Position(3,2)};
        cells[2]={Position(2,0),Position(2,1),Position(2,2),Position(2,3)};
        cells[3]={Position(0,1),Position(1,1),Position(2,1),Position(3,1)};
        Move(-1,3);
    }
};
class OBlock:public Block{
    public:
    OBlock()
    {
        id=4;
        cells[0]={Position(0,0),Position(0,1),Position(1,0),Position(1,1)};//when the lblock is in 0 state the then the following cells are occupied
        Move(0,4);//to move the block to the center position
    }
};
class SBlock:public Block{
    public:
    SBlock()
    {
        id=5;
        cells[0]={Position(0,1),Position(0,2),Position(1,0),Position(1,1)};//when the lblock is in 0 state the then the following cells are occupied
        cells[1]={Position(0,1),Position(1,1),Position(1,2),Position(2,2)};
        cells[2]={Position(1,1),Position(1,2),Position(2,0),Position(2,1)};
        cells[3]={Position(0,0),Position(1,0),Position(1,1),Position(2,1)};
        Move(0,3);
    }
};
class TBlock:public Block{
    public:
    TBlock()
    {
        id=6;
        cells[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)}; // 0 degrees
cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)}; // 90 degrees
cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)}; // 180 degrees
cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)}; // 270 degrees
        Move(0,3);
    }
};
class ZBlock:public Block{
    public:
    ZBlock()
    {
        id=7;
        cells[0]={Position(0,0),Position(0,1),Position(1,1),Position(1,2)};//when the lblock is in 0 state the then the following cells are occupied
        cells[1]={Position(0,2),Position(1,1),Position(1,2),Position(2,1)};
        cells[2]={Position(1,0),Position(1,1),Position(2,1),Position(2,2)};
        cells[3]={Position(0,1),Position(1,0),Position(1,1),Position(2,0)};
        Move(0,3);
    }
};