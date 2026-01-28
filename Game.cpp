#include "Game.h"
#include<random>

Game::Game()
{
    grid=Grid();
    blocks=GetAllBlock();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    gameover=false;
    score = 0;
    InitAudioDevice();
    music=LoadMusicStream("Sound/music.mp3");
    PlayMusicStream(music);
    rotatesound = LoadSound("Sound/rotate.mp3");
    clearsound = LoadSound("Sound/clear.mp3"); 
}
Game::~Game(){
    UnloadSound(rotatesound);
    UnloadSound(clearsound);
    UnloadMusicStream(music);
    CloseAudioDevice();
    
}
//is used to get random block from the vector
Block Game::GetRandomBlock()
{

    //to check if the block is empty ie: vector
    if(blocks.empty())
    {
        blocks=GetAllBlock();
    }
    int randomIndex=rand() % blocks.size();//is used to get randomly value to index the block vector
    Block block=blocks[randomIndex];
    blocks.erase(blocks.begin()+randomIndex);//to erase and next time it will not be available
    return block;
}
//to get the block if the blocks are empty
vector<Block> Game::GetAllBlock()
{
    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}
void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11,11);
    switch(nextBlock.id)
    {
    case 3:
         nextBlock.Draw(255,290);
         break;
     case 4:
         nextBlock.Draw(255,280);
         break;
    default:
          nextBlock.Draw(270,270);
          break;
    }
}
//control by pressing the key by the user
void Game::HandleInput()
{
    int keyPressed=GetKeyPressed();//using raylib function
    if(gameover && keyPressed != 0)
    {
        gameover=false;
        Reset();
    }
    switch(keyPressed)
    {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            updateScore(0,1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}
void Game:: MoveBlockLeft()
{
    if(!gameover)
    {
        currentBlock.Move(0,-1);
    if(IsBlockOutside()|| BlockFits() == false)
   {
    currentBlock.Move(0,1);
   }
   }
}


void Game:: MoveBlockRight()
{
    if(!gameover)
    {
   currentBlock.Move(0,1); 
   if(IsBlockOutside()|| BlockFits() == false)
   {
    currentBlock.Move(0,-1);
   }
   }
}


void Game::MoveBlockDown()
{
    if(!gameover)
    {
    currentBlock.Move(1,0);
    if(IsBlockOutside()|| BlockFits() == false)
   {
    currentBlock.Move(-1,0);
    LockBlock();
   }
    }
}

bool Game::IsBlockOutside()
{
    vector<Position> tiles= currentBlock.GetCellPositions();
    for(Position item:tiles)
    {
        if(grid.IsCellOutside(item.row,item.cols))
        {
            return true;
        }

    }
    return false;
}

void Game::RotateBlock()
{
    if(!gameover)
    {
    currentBlock.Rotate();
    if(IsBlockOutside() || BlockFits() == false)
    {
        currentBlock.UndoRotation(); 
    }
        else{
            PlaySound(rotatesound);
        }
    }
}

void Game::LockBlock()
{
    vector<Position> tiles= currentBlock.GetCellPositions();
    for(Position item:tiles)
    {
        grid.grid[item.row][item.cols]= currentBlock.id;
    }
    currentBlock=nextBlock;
    if(BlockFits()==false)
    {
        gameover=true;
    }
    nextBlock = GetRandomBlock();
    int rowscleared=grid.clearFullRows();
    if(rowscleared>0)
    {
        PlaySound(clearsound);
    updateScore(rowscleared,0);
    }
}

bool Game::BlockFits()
{
    vector<Position> tiles =currentBlock.GetCellPositions();
    for(Position item: tiles)
    {
        if(grid.IsCellEmpty(item.row,item.cols)==false)
        {
            return false;
        }
        
    }
    return true;
}

void Game::Reset()
{
    grid.initialize();
    blocks=GetAllBlock();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::updateScore(int rowscleared, int movedline)
{
    switch(rowscleared)
    {
        case 1:
        score+= 100;
        break;
        case 2:
        score+=300;
        break;
        case 3:
        score+=500;
        break;
        default:
        break;
    }
    score +=movedline;
}
