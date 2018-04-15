#pragma once
#include <string>
#include "Types.h"

class Bunny 
{
public:
	Sex sex;
	Color color;
	unsigned int age;
	std::string name;
	bool radioactive_mutant_vampire_bunny;
	bool IsDying();
public:
	Bunny();
	Bunny(const Bunny &mother);
};
