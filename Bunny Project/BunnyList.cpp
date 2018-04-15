#include "stdafx.h"
#include "BunnyList.h"

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
	for (auto pBunny : *this)
	{
		if (pBunny->radioactive_mutant_vampire_bunny)
		{
			//Choose random non-radioactive bunny to convert
		}
	}
}

void BunnyList::KillHalf()
{
	//Randomly choose bunny_list.size() / 2 bunnies to kill
}

void BunnyList::push_back(std::shared_ptr<Bunny> pBunny)
{
	std::list <std::shared_ptr<Bunny>>::push_back(pBunny);
	if (pBunny->radioactive_mutant_vampire_bunny)
	{
		num_radioactive++;
	}
}



