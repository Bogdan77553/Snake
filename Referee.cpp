#include "Referee.h"

namespace SnakeGame
{
	void Referee::showResult()
	{
		settings.SetCursorPosition(xPoint, yPoint);
		std::cout << "Points";
		settings.SetCursorPosition(xPoint + 3, yPoint + 1);
		std::cout << point;
	}
	void Referee::incrementPoint(void)
	{
		point++;
	}
	void Referee::resetPoint(void)
	{
		point = 0;
	}
}