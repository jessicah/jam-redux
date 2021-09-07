#include "types.h"

#include <unordered_map>

std::unordered_map<std::string, Rule> Rule::rules;
std::unordered_map<std::string, Target> Target::targets;

Rule& Rule::bind(const std::string &name)
{
	auto &rule = Rule::rules[name];

	if (rule.name.empty())
	{
		rule.name = name;
	}

	return rule;
}


Target& Target::bind(const std::string &name)
{
	auto &target = Target::targets[name];

	if (target.name.empty()) {
		target.name = name;
		target.bound_name = name;
	}

	return target;
}


// Target copy_target is the copy-constructor


void Target::touch(const std::string &name)
{
	auto &target = Target::bind(name);

	target.flags |= TargetFlags::Touched;
}


Targets chain_targets(Targets &chain, Targets &targets)
{
	if (targets.empty())
		return chain;
	if (chain.empty())
		return targets;
	
	// a chain has a tail, what is it used for?
	return {};
}