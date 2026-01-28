#pragma once
#include "grid.h"
#include "occupied_position.cpp"
//this class is used as container to hold object of all the element of our game like: grid,position of block..
class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();

        void MoveBlockDown();

        Grid grid;
        bool gameover;

        int score;
        Music music;

    private:
    std::vector<Block> blocks;//this holds all the block
    Block currentBlock;
    Block nextBlock;
        Block GetRandomBlock();
        vector<Block> GetAllBlock();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void updateScore( int linecleared,int movedline);
    Sound rotatesound;
    Sound clearsound;
};