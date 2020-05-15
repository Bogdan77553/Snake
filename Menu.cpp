#include "Menu.h"

namespace SnakeGame
{
    Submenu Menu::run(int x, int y)
    {
        Section section{ 28,10 };
        clear();
        section.DrawPoint('*');

        Submenu submenu = Submenu::DEFAULT;
        bool continuum = false;
        show(x, y);

        while (!continuum)
        {
            switch (GetKeyCommand())
            {
            case Key::UP:
                section.ClearPoint();
                swithUp(section);
                section.DrawPoint('*');
                Sleep(200);
                break;
            case Key::DOWN:
                section.ClearPoint();
                swithDown(section);
                section.DrawPoint('*');
                Sleep(200);
                break;
            case Key::ESCAPE:
                Sleep(200);
                continuum = true;
                submenu = Submenu::CONTINUUM;
                break;
            case Key::SPACE:

                break;
            case Key::ENTER:
                if (section.y == 10)
                    submenu = Submenu::CONTINUUM;
                if (section.y == 11)
                    submenu = Submenu::START;
                if (section.y == 12)
                    submenu = Submenu::SMTH;
                if (section.y == 13)
                    submenu = Submenu::EXIT;

                continuum = true;
                break;

            default:
                break;
            }
        }
        clear();
        return submenu;
    }
    Key Menu::GetKeyCommand(void)
    {
        Key key = Key::DEFAULT;
        if (GetAsyncKeyState(VK_UP))
        {
            key = Key::UP;
        }
        else
            if (GetAsyncKeyState(VK_DOWN))
            {
                key = Key::DOWN;
            }
            else
                if (GetAsyncKeyState(VK_RETURN))
                {
                    key = Key::ENTER;
                }
                else
                    if (GetAsyncKeyState(VK_ESCAPE))
                    {
                        key = Key::ESCAPE;
                    }
                    else
                        if (GetAsyncKeyState(VK_SPACE))
                        {
                            key = Key::SPACE;
                        }
        return key;
    }

    void Menu::clear()
    {
        Settings settings;
        for (int i = 8; i <= 15; i++)
        {
            settings.SetCursorPosition(18, i);
            std::cout << "                                    ";
        }
    }

    void Menu::swithUp(Section& cell)
    {
        if (cell.y > 10)
        {
            cell.y--;
        }
    }

    void Menu::swithDown(Section& cell)
    {
        if (cell.y < 13)
        {
            cell.y++;
        }
    }

    void Menu::show(int x, int y)
    {
        Settings settings;
        settings.SetCursorPosition(x, y);
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        settings.SetCursorPosition(x, y + 7);
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

        for (int i = y; i <= y + 7; i++)
        {
            settings.SetCursorPosition(x, i);
            std::cout << "@";
            settings.SetCursorPosition(x + 35, i);
            std::cout << "@";
        }


        settings.SetCursorPosition(x + 12, y + 2);
        std::cout << "Continuum";

        settings.SetCursorPosition(x + 12, y + 3);
        std::cout << "Start new game";

        settings.SetCursorPosition(x + 12, y + 4);
        std::cout << "Smth";

        settings.SetCursorPosition(x + 12, y + 5);
        std::cout << "Exit";
    }
}