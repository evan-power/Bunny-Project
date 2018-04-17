// Bunny Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include "Bunny.h"
#include <memory>
#include "BunnyList.h"

#include <iostream>
#include <fstream>

const std::string OUT_FILENAME = "out.txt";
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
	std::ofstream outFile(OUT_FILENAME);
	
	for (int i = 0; i < INITIAL_BUNNIES; i++)
	{
		bunny_list.push_back(std::make_shared<Bunny>());
	}

	outFile << "Bunny Simulation" << std::endl;
	outFile << "----------------" << std::endl;
	while(bunny_list.size() > 0)
	{
		outFile << "New Turn" << std::endl;
		DoTurn(bunny_list);
	}
	
    return 0;
}

