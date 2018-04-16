#pragma once
#include <array>
#include <vector>
enum Sex { MALE, FEMALE };
enum Color { WHITE, BROWN, BLACK, SPOTTED };

inline std::string ColorToString(Color color)
{
	std::string colorNames[] = { "white", "brown", "black", "spotted" };
	return colorNames[color];
}