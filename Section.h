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

        void ClearPoint()
        {
            settings.SetCursorPosition(x, y);
            std::cout << ' ';
        }
       

        void DrawPoint(char symbol)
        {
            settings.SetCursorPosition(x, y);
            std::cout << symbol;
        }

    private:
        Settings settings;
        
    };

}