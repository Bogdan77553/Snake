#pragma once
#include <iostream>
#include "Settings.h"

namespace SnakeGame
{
    class Section
    {
    public:
        int x;
        int y;
        Section() {}

        Section(int inX, int inY)
            : x(inX)
            , y(inY)
        {}
        void ClearPoint(); 
        void DrawPoint(char symbol);

    private:
        Settings settings;        
    };
}