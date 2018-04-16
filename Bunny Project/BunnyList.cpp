#include "stdafx.h"
#include "BunnyList.h"
#include "rand.h"
#include <queue>
#include <iostream>

BunnyList::BunnyList()
{
	num_radioactive = 0;
}

bool BunnyList::FertileMaleExists()
{
	for (auto pBunny :*this)
	{
		if (pBunny->sex == FEMALE && pBunny->age >= 2)
		{
			return true;
		}
	}
	return false;
}

void BunnyList::CreateNewBunnies()
{
	//for (auto iter = begin(); iter != end(); ++iter)
	for (auto pBunny : *this)
	{
		if (pBunny->sex == FEMALE && pBunny->age >= 2 && !pBunny->radioactive_mutant_vampire_bunny)
		{
			push_back(std::make_shared<Bunny>(*pBunny));
		}
	}
}

void BunnyList::KillOldBunnies()
{
	for (auto iter = begin(); iter != end(); ++iter)
	{
		auto pBunny = *iter;
		if (pBunny->IsDying())
		{
			erase(iter++);
		}
	}
}

void BunnyList::ConvertToRadioactive()
{	
	std::vector <std::shared_ptr<Bunny>> nonrad_bunnies;

	for (auto pBunny : *this)
	{
		if (!pBunny->radioactive_mutant_vampire_bunny)
		{
			nonrad_bunnies.push_back(pBunny);
		}
	}

	int rand_nonrad = 0;
	for (auto pBunny : nonrad_bunnies)
	{
		rand_nonrad = rand_int(0, nonrad_bunnies.size() - 1);
		nonrad_bunnies[rand_int(0, rand_nonrad)]->radioactive_mutant_vampire_bunny = true;
		nonrad_bunnies.erase(nonrad_bunnies.begin() + rand_nonrad);
	}
}

void BunnyList::KillHalf()
{	
	std::vector<int> rand_bunnies;
	rand_bunnies.reserve(size() / 2);
	for (int i = 0; i < size() / 2; i++)
	{
		rand_bunnies.push_back(rand_int(0, size() - 1));
	}
	std::sort(rand_bunnies.begin(), rand_bunnies.end());

	int current_index = 0;
	int rand_bunny_index = 0;
	for (auto iter = begin(); iter != end(); ++iter)
	{
		if (rand_bunnies[rand_bunny_index] == current_index)
		{
			rand_bunnies.erase(rand_bunnies.begin() + rand_bunny_index);
			erase(iter);
			rand_bunny_index++;
		}
		else
		{
			current_index++;
		}
	}
}

void BunnyList::OutputBunnies()
{
	for (auto pBunny : *this)
	{
		if (pBunny->radioactive_mutant_vampire_bunny)
		{
			std::cout << "Radioactive Mutant Vampire" << pBunny->name << "\tAge:" << pBunny->age << "\tSex:" << ((pBunny->sex == MALE) ? "Male" : "Female") << "\tColor" << color[pBunny->color] << std::endl;
		}
		else
		{
			std::cout << pBunny->name << "\tAge:" << pBunny->age << "\tSex:" << ((pBunny->sex == MALE) ? "Male" : "Female") << "\tColor" << color[pBunny->color] << std::endl;
		}
	}
}

void BunnyList::push_back(std::shared_ptr<Bunny> pBunny)
{
	std::list <std::shared_ptr<Bunny>>::push_back(pBunny);
	if (pBunny->radioactive_mutant_vampire_bunny)
	{
		num_radioactive++;
	}
}



