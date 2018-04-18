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
		if (pBunny->GetSex() == FEMALE && pBunny->GetAge() >= 2)
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
		if (pBunny->GetSex() == FEMALE && pBunny->GetAge() >= 2 && !pBunny->GetRadioactivity())
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
		if (!pBunny->GetRadioactivity())
		{
			nonrad_bunnies.push_back(pBunny);
		}
	}

	int rand_nonrad = 0;
	for (auto pBunny : nonrad_bunnies)
	{
		rand_nonrad = rand_int(0, (int)nonrad_bunnies.size() - 1);
		nonrad_bunnies[rand_int(0, (int)rand_nonrad)]->SetRadioactivity(true);
		nonrad_bunnies.erase(nonrad_bunnies.begin() + rand_nonrad);
	}
}

void BunnyList::KillHalf()
{	
	std::vector<int> rand_bunnies;
	rand_bunnies.reserve(size() / 2);
	for (int i = 0; i < (int)size() / 2; i++)
	{
		rand_bunnies.push_back(rand_int(0, (int)size() - 1));
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

void BunnyList::AgeBunnies()
{
	for (auto pBunny : *this)
	{
		pBunny->IncrementAge();
	}
}

void BunnyList::OutputBunnies(std::ostream &out_stream)
{
	for (auto pBunny : *this)
	{
		if (pBunny->GetRadioactivity())
		{
			std::cout << "Radioactive Mutant Vampire " << pBunny->GetName() << "    Age: " << pBunny->GetAge() << "    Sex: " << ((pBunny->GetSex() == MALE) ? "male" : "female") << "    Color: " << ColorToString(pBunny->GetColor()) << std::endl;
			out_stream << "Radioactive Mutant Vampire " << pBunny->GetName() << "    Age: " << pBunny->GetAge() << "    Sex: " << ((pBunny->GetSex() == MALE) ? "male" : "female") << "    Color: " << ColorToString(pBunny->GetColor()) << std::endl;
		}
		else
		{
			std::cout << pBunny->GetName() << "    Age: " << pBunny->GetAge() << "    Sex: " << ((pBunny->GetSex() == MALE) ? "male" : "female") << "    Color: " << ColorToString(pBunny->GetColor()) << std::endl;
			out_stream << pBunny->GetName() << "    Age: " << pBunny->GetAge() << "    Sex: " << ((pBunny->GetSex() == MALE) ? "male" : "female") << "    Color: " << ColorToString(pBunny->GetColor()) << std::endl;
		}
	}
}

void BunnyList::push_back(std::shared_ptr<Bunny> pBunny)
{
	std::list <std::shared_ptr<Bunny>>::push_back(pBunny);
	if (pBunny->GetRadioactivity())
	{
		num_radioactive++;
	}
}



