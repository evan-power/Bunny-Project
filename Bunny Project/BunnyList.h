#pragma once
#include "Bunny.h"
#include <list>
#include <memory>

class BunnyList : public std::list <std::shared_ptr<Bunny>>
{
	int num_radioactive;
public:
	BunnyList();

	bool FertileMaleExists();
	void CreateNewBunnies();
	void KillOldBunnies();
	void ConvertToRadioactive();
	void KillHalf();
	void OutputBunnies();
	void push_back(std::shared_ptr<Bunny>);

	
};

