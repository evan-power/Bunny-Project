// Bunny Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include "Bunny.h"
#include <memory>
#include "BunnyList.h"

//typedef std::list<std::shared_ptr<Bunny> > BunnyList;

const int INITIAL_BUNNIES = 5;

//for (BunnyList::iterator iter = bunny_list.begin(); iter != bunny_list.end(); ++iter)
//for (auto iter = bunny_list.begin(); iter != bunny_list.end(); ++iter)

void DoTurn(BunnyList &bunny_list)
{
	if (bunny_list.FertileMaleExists())
	{
		bunny_list.CreateNewBunnies();
	}

	bunny_list.KillOldBunnies();
	bunny_list.ConvertToRadioactive();
	
	if (bunny_list.size() > 1000)
	{
		bunny_list.KillHalf();
	}

	bunny_list.OutputBunnies();
}

int main()
{
	BunnyList bunny_list;
	
	for (int i = 0; i < INITIAL_BUNNIES; i++)
	{
		bunny_list.push_back(std::make_shared<Bunny>());
	}

	while(bunny_list.size() > 0)
	{
		DoTurn(bunny_list);
	}
	
    return 0;
}

