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

        void reset(int x, int y, int l)
        {
            for (auto itr = body.begin();
                itr != body.end(); itr++) {
                itr->DrawPoint(' ');
            }
            body.clear();
            generate(x, y, l);
        }

        void freeze()
        {
            stopMove = true;
        }
        void unfreeze()
        {
            stopMove = false;            
            
            for (auto itr = body.begin();
                itr != body.end(); itr++) 
            {
                itr->DrawPoint('*');
            }

            food.DrawPoint('r'); 
        }
        
        //most suitable if this method will have it own class (like Control class)
        //but I leave it here
        bool GetKeyCommand(void)
        {
            bool result = false;
            if (autopilot) {
                // ...
            }
            else
            {
                if (GetAsyncKeyState(VK_LEFT))
                {
                    setDirection(Direction::LEFT);
                    result = true;
                }
                else
                    if (GetAsyncKeyState(VK_UP))
                    {
                        setDirection(SnakeGame::Direction::UP);
                        result = true;
                    }
                    else
                        if (GetAsyncKeyState(VK_RIGHT))
                        {
                            setDirection(SnakeGame::Direction::RIGHT);
                            result = true;
                        }
                        else
                            if (GetAsyncKeyState(VK_DOWN))
                            {
                                setDirection(SnakeGame::Direction::DOWN);
                                result = true;
                            }
            }
            
            return result;
        }

        void Move()
        {
            if (!stopMove)
            {
                Section tail = body.back();
                tail.ClearPoint();//витерти з консолі хвіст

                Section head = GetNextPoint(); //отримати позицію нового кроку
                body.push_front(head);       //додати цю позицію в тіло
                body.pop_back();  //отримати та видалити останню позицію хвоста (first in the queue)

                head.DrawPoint('*'); //намалювати на консолі голову
            }
            
        }

        bool Eat(Section& p)
        {
            bool result = false;
            food.x = p.x; //our Snake always know about actual position of food section
            food.y = p.y;
            
            Section head = GetHead();
            if ((head.x == p.x) && ((head.y == p.y)))
            {
                head = GetNextPoint();
                body.push_front(head);
                head.DrawPoint('*');
                result = true;
            }
            return result;
        }

        bool IsCrash()
        {
            bool result = false;
            Section head = GetHead();
            int temp = body.size();

            if (body.size() > 1)
            {
                if (WallCrash(head) || OwnCrash(head))
                {
                    result = true;
                }
            }            
            return result;
        }

        ~Snake() {
            
        }


    private:
        std::list<Section> body; //  I don't use std::queue because it hasn't iterators. It's necessary for OwnCrash()
        Direction direction;
        int length;
        int maxX;
        int maxY;
        bool autopilot;
        Section food; //last valid position of food. Need for autopilot
        bool stopMove;

        void generate(int x, int y, int l)
        {
            direction = Direction::RIGHT;
            length = l;
            //body = new std::list<Section>();
            for (int i = x - l; i < x; i++)
            {
                Section p{ i, y };
                body.push_front(p);
                p.DrawPoint('*');
            }
        }

        bool WallCrash(Section& head)
        {
            bool result = false;
            if (
                (head.x >= 69) || (head.y == 0) ||
                (head.x == 0) || (head.y >= 30)
                )
            {
                result = true;
            }
            return result;
        }

        bool OwnCrash(Section& head)
        {
            bool result = false;
            auto itr = body.begin();
            *itr++; // miss first element because we don't want compare gotted Head with current Head in Body
            for (;
                itr != body.end(); itr++) {
                if ((head.x == itr->x) && ((head.y == itr->y)))
                {
                    result = true;
                }
            }
            return result;
        }

        void setDirection(Direction drctn)
        {
            direction = drctn;
        }

        Section GetHead() 
        {
            Section p = body.front();
            return p;
        }

        Section GetNextPoint()
        {
            Section p = GetHead();
            switch (direction)
            {
            case Direction::LEFT:
                p.x--;
                break;
            case Direction::RIGHT:
                p.x++;
                break;
            case Direction::UP:
                p.y--;
                break;
            case Direction::DOWN:
                p.y++;
                break;
            }
            return p;
        }
    };

}

