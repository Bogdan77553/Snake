#pragma once
#include "Settings.h"
#include "iostream"


namespace SnakeGame
{
	class Referee
	{
	public:
		Referee(unsigned int xP, unsigned int yP)
			:point(0)
			, xPoint(xP)
			, yPoint(yP)
		{}
		void showResult()
		{
			settings.SetCursorPosition(xPoint, yPoint);
			std::cout << "Points";
			settings.SetCursorPosition(xPoint+3, yPoint+1);
			std::cout << point;
		}
		void incrementPoint(void) 
		{
			point++;
		}
		void resetPoint(void) 
		{
			point = 0;
		}
	private:
		unsigned int point;
		unsigned int xPoint;
		unsigned int yPoint;
		Settings settings;


	};

}