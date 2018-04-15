#include "stdafx.h"
#include "Bunny.h"
#include "rand.h"
#include <ctime>

constexpr int MAX_NONRADIOACTIVE_AGE = 10;
constexpr int MAX_RADIOACTIVE_AGE = 50;

Bunny::Bunny() 
{
	age = 0;
	sex = rand_int(0, 1) ? MALE : FEMALE;
	radioactive_mutant_vampire_bunny = rand_int(1,100) <= 2;

	color = static_cast<Color>(rand_int(static_cast<int>(WHITE), static_cast<int>(SPOTTED)));
}

Bunny::Bunny(const Bunny &mother)
{
	age = 0;
	sex = rand_int(0, 1) ? MALE : FEMALE;
	radioactive_mutant_vampire_bunny = rand_int(1, 100) <= 2;
	color = mother.color;
}

bool Bunny::IsDying()
{
	const bool nonradioactive_dying = age > MAX_NONRADIOACTIVE_AGE && !radioactive_mutant_vampire_bunny;
	const bool radioactive_dying = age > MAX_RADIOACTIVE_AGE && radioactive_mutant_vampire_bunny;
	return  nonradioactive_dying || radioactive_dying;
}