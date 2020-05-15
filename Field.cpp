#include "Field.h"

namespace SnakeGame
{
    void Field::DrawHor(int x)
    {
        for (int i = 0; i < 31; i++)
        {
            Section p{ x, i };
            p.DrawPoint('#');
        }
    }

    void Field::DrawVer(int y)
    {
        for (int i = 0; i < 70; i++)
        {
            Section p{ i, y };
            p.DrawPoint('#');
        }
    }
}
