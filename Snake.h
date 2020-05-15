#pragma once
#include "Section.h"
#include <Windows.h>
#include <list>


namespace SnakeGame
{
    enum class Direction
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    class Snake
    {

    public:

        Snake(int x, int y, int l, int MaxX, int MaxY, bool autoplt = false )
            :maxX(MaxX)
            , maxY(MaxY)
            , autopilot(autoplt)
        {
            stopMove = false;
            generate(x, y, l);
        }       

        void reset(int x, int y, int l);
        void freeze();
        void unfreeze();        
        bool GetKeyCommand(void);
        void Move();
        bool Eat(Section& p);
        bool IsCrash();
        ~Snake() {}

    private:
        std::list<Section> body; //  I don't use std::queue because it hasn't iterators. It's necessary for OwnCrash()
        Direction direction;
        int length;
        int maxX;
        int maxY;
        bool autopilot;
        Section food; //last valid position of food. Need for autopilot
        bool stopMove;

        void generate(int x, int y, int l);
        bool WallCrash(Section& head);
        bool OwnCrash(Section& head);
        void setDirection(Direction drctn);
        Section GetHead();
        Section GetNextPoint();
    };

}

