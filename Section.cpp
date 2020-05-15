#include "Section.h"
#include "Settings.h"


namespace SnakeGame
{
    void Section::ClearPoint()
    {
        settings.SetCursorPosition(x, y);
        std::cout << ' ';
    }

    void Section::DrawPoint(char symbol)
    {
        settings.SetCursorPosition(x, y);
        std::cout << symbol;
    }
}