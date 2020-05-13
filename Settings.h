#pragma once

//#include <Windows.h>

namespace SnakeGame
{
    class Settings
    {
    public:
        void ConsoleCursorVisible(bool visibility);
        void SetWindow(int Width, int Height);
        //void SetColor(WORD color);
        void SetCursorPosition(int x, int y);
    };
}
