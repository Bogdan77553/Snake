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
		void showResult();
		void incrementPoint(void);
		void resetPoint(void);

	private:
		unsigned int point;
		unsigned int xPoint;
		unsigned int yPoint;

		Settings settings;
	};
}