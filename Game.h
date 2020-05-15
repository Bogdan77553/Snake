#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <mutex>

#include "Settings.h"
#include "Field.h"


#include "Snake.h"
#include "Food.h"
#include "Referee.h"
#include "Menu.h"

namespace SnakeGame
{
    class Game
    {
    public:
        Game(int fieldX, int fieldY, int pointPlaceX, int pointPlaceY)
            :FieldX(fieldX)
            ,FieldY(fieldY)
            ,PointX(pointPlaceX)
            ,PointY(pointPlaceY)
        {}
        void Start();        
        void Over();
        void GameLoop(std::mutex& mtx); //,  SnakeGame::Game& game       
        
    private:
        void show();
        void clear();

        int PointX;
        int PointY;
        int FieldX;
        int FieldY;
        Snake snake{ 7,7,3,FieldX,FieldY };
        Referee referee{ PointX, PointY };
        Menu menu;
        SimpleFood simpleFood;
    };
}
