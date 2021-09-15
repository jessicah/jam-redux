#include "types.h"

std::unordered_map<std::string, Variable> Variable::all;

bool Variable::get(const std::string &name, Variable &out)
{
	auto it = Variable::all.find(name);

	// TODO: a variable without any values, should we say we found the
	// variable? or say it's not found?
	if (it != Variable::all.end() && it->second.values.empty() == false)
	{
		out.name = it->second.name;
		out.values = it->second.values;

		return true;
	}

	return false;
}