#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>
#include "Header.h"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
//		Solver mySolver("input.txt");
//		std::cout << mySolver.solve() << '\n';
		system("pause");
		return 0;
	}
	else
	{
		Solver mySolver(argv[1]);
		std::cout << mySolver.solve() << '\n';
		return 0;
	}
}
