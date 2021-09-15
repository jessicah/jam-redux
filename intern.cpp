#include "intern.h"

#include <iostream>
#include <unordered_set>
#include <utility>


static std::unordered_set<std::string> interned_strings;


const std::string &
intern(const std::string_view &input)
{
	std::cout << "interning " << input << std::endl;

	auto it = interned_strings.insert(std::string(input.begin(), input.end()));
	
	if (it.second == false)
	{
		std::cout << "retrieved interned string: " << *it.first << std::endl;
	}
	else
	{
		std::cout << "added new interned string: " << *it.first << std::endl;
	}
	
	return *it.first;
}
