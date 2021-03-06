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


void DoTurn(BunnyList &bunny_list, std::ostream &out_stream)
{
	std::cout << std::endl << "New Turn" << std::endl;
	out_stream << std::endl << "New Turn" << std::endl;
	std::cout << "----------------" << std::endl;
	out_stream << "----------------" << std::endl;

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

	bunny_list.OutputBunnies(out_stream);
	bunny_list.AgeBunnies();
	std::cout << std::endl << std::endl;
	std::cout << "Press enter for next turn." << std::endl;
	std::cin.get();
}

int main()
{
	BunnyList bunny_list;
	std::ofstream out_file(OUT_FILENAME);

	for (int i = 0; i < INITIAL_BUNNIES; i++)
	{
		bunny_list.push_back(std::make_shared<Bunny>());
	}

	out_file << "Bunny Simulation" << std::endl;
	out_file << "----------------" << std::endl;
	while(bunny_list.size() > 0)
	{
		DoTurn(bunny_list, out_file);
	}
	
    return 0;
}

