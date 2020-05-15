#include "Game.h"
namespace SnakeGame
{
    void Game::GameLoop(std::mutex& mtx) //,  SnakeGame::Game& game
    {
        SnakeGame::FoodFactory foodFactory(FieldX, FieldY);
        Start();
        menu.run(18, 8);
        foodFactory.CreateFood(simpleFood);

        while (1)
        {
            mtx.lock();
            referee.showResult();
            snake.GetKeyCommand();

            snake.Move();

            if (snake.Eat(simpleFood.Get()))
            {
                foodFactory.CreateFood(simpleFood);
                referee.incrementPoint();
            }

            if (snake.IsCrash())
            {
                Over();
                referee.resetPoint();
                while (!snake.GetKeyCommand());

                snake.reset(5, 5, 3);
                Start();
                simpleFood.Eat();
                foodFactory.CreateFood(simpleFood);
            }

            if (menu.GetKeyCommand() == Key::SPACE)
            {
                snake.freeze();
                while (!snake.GetKeyCommand());
                snake.unfreeze();
            }

            if (menu.GetKeyCommand() == Key::ESCAPE)
            {
                Sleep(100);
                snake.freeze();
                menu.run(18, 8);
                snake.unfreeze();
            }

            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));

        }
    }

    void Game::Start()
    {
        Settings settings;

        settings.SetWindow(80, 31);
        settings.ConsoleCursorVisible(false);

        clear();

        Field field;
        settings.SetCursorPosition(0, 0);
        field.DrawHor(0);
        field.DrawHor(70);
        field.DrawVer(0);
        field.DrawVer(30);

    }
    void Game::Over()
    {
        show();
    }

    void Game::show()
    {
        Settings settings;
        settings.SetCursorPosition(27, 9);
        std::cout << "@@@@@@@@@@@@@@@@@@";
        settings.SetCursorPosition(27, 13);
        std::cout << "@@@@@@@@@@@@@@@@@@";

        for (int i = 9; i < 14; i++)
        {
            settings.SetCursorPosition(27, i);
            std::cout << "@";
            settings.SetCursorPosition(45, i);
            std::cout << "@";
        }
        settings.SetCursorPosition(32, 11);
        std::cout << "GAME OVER";
    }
    void Game::clear()
    {
        Settings settings;
        for (int i = 0; i < 30; i++)
        {
            settings.SetCursorPosition(0, i);
            std::cout << "                                                                               ";
        }
    }
}