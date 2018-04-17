#include "stdafx.h"
#include "Bunny.h"
#include "rand.h"
#include <iostream>

constexpr int MAX_NONRADIOACTIVE_AGE = 10;
constexpr int MAX_RADIOACTIVE_AGE = 50;


std::vector<std::string> Bunny::names = { "Arnold", "Bam Bam", "Geoffrey", "Snickers", "Cosmo", 
	"Spot", "Bilbo", "Darrow", "Rex", "Pluto", "Shakespeare", "Spice", "Coda", "Mars", "Thumper", 
	"Bomber", "Dough Boy", "Tripper", "Chad", "Dalton", "Butter", "Gucci", "Gremlin", "Jersey",
	"Stormie", "Smudge", "Gringo", "Anastasia", "Fluffy", "Bumper", "Pepsi", "Ajax", "Beefeater",
	"Alf", "Beebo", "Cheezels", "Tequila", "Mercedes", "Nibbles", "Pancake", "Paris", "Stripe"};

bool Bunny::IsDying()
{
	const bool nonradioactive_dying = age > MAX_NONRADIOACTIVE_AGE && !radioactive_mutant_vampire_bunny;
	const bool radioactive_dying = age > MAX_RADIOACTIVE_AGE && radioactive_mutant_vampire_bunny;
	return  nonradioactive_dying || radioactive_dying;
}

Bunny::Bunny() 
{
	name = names[rand_int(0, (int)names.size() - 1)];
	age = 0;
	sex = rand_int(0, 1) ? MALE : FEMALE;
	radioactive_mutant_vampire_bunny = rand_int(1, 100) <= 2;
	if (radioactive_mutant_vampire_bunny)
	{
		name = "Radioactive Mutant Vampire Bunny " + name;
	}
	
	std::cout << name << " was born!" << std::endl;
	color = static_cast<Color>(rand_int(static_cast<int>(WHITE), static_cast<int>(SPOTTED)));	
}

Bunny::Bunny(const Bunny &mother)
{
	name = names[rand_int(0, (int)names.size() - 1)];
	age = 0;
	sex = rand_int(0, 1) ? MALE : FEMALE;
	radioactive_mutant_vampire_bunny = rand_int(1,100) <= 2;
	if (radioactive_mutant_vampire_bunny)
	{
		name = "Radioactive Mutant Vampire Bunny " + name;
	}

	std::cout << name << " was born!" << std::endl;
	color = mother.color;
}

Bunny::~Bunny()
{
	std::cout << GetName() << " has died!" << std::endl;
}