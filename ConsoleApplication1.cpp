#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <mutex>

#include "Game.h"

#include "Settings.h"
#include "Field.h"
#include "Snake.h"
#include "Food.h"
#include "Referee.h"
#include "Menu.h"



static void TestLoop(std::mutex& mtx)
{
    using namespace std::literals::chrono_literals;
    //SnakeGame::Point p;
    SnakeGame::Settings settings;
    while (1)
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(3s);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;

        //mtx.lock();
        settings.ConsoleCursorVisible(false);
        
        //std::cout << duration.count() << std::endl;
        //mtx.unlock();        
    }
}

int main()
{
    SnakeGame::Game game{ 69,29,72,5};

    std::mutex mtx;

    std::thread timerIRQ(TestLoop, ref(mtx));
    std::thread timerIRQ1(&SnakeGame::Game::GameLoop, game, ref(mtx));

    timerIRQ.join();
    timerIRQ1.join();
}


