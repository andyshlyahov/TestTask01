#pragma once

#include <string>

class Solver
{
public:
	Solver();
	Solver(std::string filename_);
	float solve();
	void setFileName(std::string filename_);
private:
	std::string filename;
};