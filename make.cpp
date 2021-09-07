#include "make.h"
#include "types.h"

#include <iostream>

/*
enum fate {
	INIT,
	MAKING,
	STABLE,
	NEWER,
	TEMP,
	TOUCHED,
	MISSING,
	NEED_TEMP,
	OLD,
	UPDATE,
	NO_FIND,
	NO_MAKE,
};

enum bind {
	UNBOUND,
	MISSING,
	PARENTS,
	EXISTS
};*/

bool
make(std::vector<std::string> &targets)
{
	counts counts;

	for (auto &target : targets)
	{
		std::cout << target << std::endl;
	}

	return true;
}