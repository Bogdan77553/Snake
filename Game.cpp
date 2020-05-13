#include "Game.h"

void SnakeGame::Game::GameLoop(std::mutex& mtx) //,  SnakeGame::Game& game
{    
    SnakeGame::FoodFactory foodFactory(FieldX, FieldY);
    Start();
    menu.run(18,8);
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
            menu.run(18,8);
            snake.unfreeze();
        }

        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

    }
}