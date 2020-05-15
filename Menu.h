#pragma once
#include "Settings.h"
#include <iostream>
#include <Windows.h>
#include "Section.h"

namespace SnakeGame
{
    enum class Key
    {
        UP,
        DOWN,
        ENTER,
        SPACE,
        ESCAPE,
        DEFAULT
    };

    enum class Submenu
    {
        CONTINUUM, 
        START,        
        SMTH,
        EXIT,
        DEFAULT
    };

	class Menu
	{
	public:
        Submenu run(int x, int y);
        Key GetKeyCommand(void);
    private:
        void clear();
        void swithUp(Section& cell);
        void swithDown(Section& cell);
        void show(int x, int y);
        
	};

}

