#pragma once

#include "Section.h"

namespace SnakeGame
{
    class IFood
    {
    public:
        void virtual Make(int X, int Y) = 0;
        void virtual Eat(void) = 0;        
    };

    class SimpleFood : public IFood
    {
    public:
        
        SimpleFood()
        {
            size = 1;
            ch = 'r';
        }
        Section& Get(void)
        {
            return food;
        }

        void Make(int X, int Y) override
        {
            food.x = X;
            food.y = Y;
            food.DrawPoint(ch);
        }
           
        void Eat(void) override
        {
            //delete food;
        }

    private:
        Section food;
        int size;
        char ch;

    };

    class FoodFactory : public SimpleFood
    {
    public:

        FoodFactory(int MAX_x, int MAX_y)
            : max_x(MAX_y)
            , max_y(MAX_y)
        {}

        virtual ~FoodFactory() {
            //delete food;
        }

        void CreateFood(IFood& food)
        {
            int b = ((rand() % 69) + 1);
            food.Make(((rand() % max_x) + 1), ((rand() % max_y) + 1));
        }
    private:
        int max_x;
        int max_y;

    };

}


