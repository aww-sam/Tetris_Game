#pragma once

#include<raylib.h>
#include<vector>
//extern variable allows us to declare variable in one file and use the program in other file

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color oragne;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightblue;
extern const Color darkblue;

std::vector<Color> GetCellColors();