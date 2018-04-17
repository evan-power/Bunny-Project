#pragma once
#include <string>
#include "Types.h"
#include "rand.h"

class Bunny 
{
	static std::vector<std::string> names;
	Sex sex;
	Color color;
	unsigned int age;
	std::string name;
	bool radioactive_mutant_vampire_bunny;
public:
	Sex GetSex() { return sex; }
	Color GetColor() { return color; }
	int GetAge() { return age; }
	std::string GetName() { return name; }
	bool GetRadioactivity() { return radioactive_mutant_vampire_bunny; }

	void IncrementAge() { age++; }
	void SetRadioactivity(bool new_radioactivity) { radioactive_mutant_vampire_bunny = new_radioactivity; }
	bool IsDying();

	Bunny();
	Bunny(const Bunny &mother);
	~Bunny();
};
