#include "Settings.h"

#include <Windows.h>

namespace SnakeGame
{
    void Settings::ConsoleCursorVisible(bool visibility)
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO     cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = visibility; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    void Settings::SetWindow(int Width, int Height)
    {
        _COORD coord;
        coord.X = Width;
        coord.Y = Height;

        _SMALL_RECT Rect;
        Rect.Top = 0;
        Rect.Left = 0;
        Rect.Bottom = Height - 1;
        Rect.Right = Width - 1;

        HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
        SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
        SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size             
    }

    /*
    void Settings::SetColor(WORD color)
    {
        HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
        SetConsoleTextAttribute(Handle, color);
    }
    */
    /*
    void print(int x, int y, char c) {
        COORD p = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
        printf("%c", c);
    }
    */

    void Settings::SetCursorPosition(int x, int y) {
        COORD pos = { x, y };
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(output, pos);
    }
}