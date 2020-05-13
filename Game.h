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
        void Start()
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
        void Over()
        {
            show();
        }

        void GameLoop(std::mutex& mtx); //,  SnakeGame::Game& game       
        
    private:
        int PointX;
        int PointY;
        int FieldX;
        int FieldY;

        SnakeGame::Snake snake{ 7,7,3,FieldX,FieldY };
        SnakeGame::Referee referee{ PointX, PointY };
        SnakeGame::Menu menu;
        SnakeGame::SimpleFood simpleFood;

        void show()
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
        void clear()
        {
            Settings settings;
            for (int i = 0; i < 30; i++)
            {
                settings.SetCursorPosition(0, i);
                std::cout << "                                                                               ";
            }
        }

    };


    

    

}
