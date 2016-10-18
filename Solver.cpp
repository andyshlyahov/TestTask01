#include "Solver.h"
#include "OrderBook.h"
#include <fstream>

Solver::Solver()
{
	filename = "";
}

Solver::Solver(std::string filename_)
{
	filename = filename_;
}

void Solver::setFileName(std::string filename_)
{
	filename = filename_;
}

float Solver::solve()
{
	std::ifstream file(filename);
	int time, id, oldTime, allTime = 0;
	char type;
	float price, answer = 0, currMax;

	OrderBook ob;

	file >> time >> type >> id >> price;
	ob.insert(time, id, price);
	oldTime = time;
	currMax = price;

	while (file >> time >> type)
	{
		if (type == 'I')
		{
			if (currMax != std::numeric_limits<float>::min())
			{
				answer += (time - oldTime) * currMax;
				allTime += (time - oldTime);
			}
			file >> id >> price;
			ob.insert(time, id, price);
			oldTime = time;
			currMax = ob.currentMax();
		}
		else
		{
			if (currMax != std::numeric_limits<float>::min())
			{
				answer += (time - oldTime) * currMax;
				allTime += (time - oldTime);
			}
			file >> id;
			ob.erase(id);
			oldTime = time;
			currMax = ob.currentMax();
		}
	}
	return 1.0 * answer / allTime;
}
