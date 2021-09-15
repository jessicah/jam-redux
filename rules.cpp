#include "types.h"

#include <algorithm>
#include <unordered_map>

std::unordered_map<std::string, Rule> Rule::rules;
std::unordered_map<std::string, std::shared_ptr<Target>> Target::targets;

Rule& Rule::bind(const std::string &name)
{
	auto &rule = Rule::rules[name];

	if (rule.name.empty())
	{
		rule.name = name;
	}

	return rule;
}


std::shared_ptr<Target> Target::bind(const std::string &name)
{
	//auto &target = Target::targets[name];
	auto target = Target::targets.try_emplace(name, std::make_shared<Target>());

	// if we've constructed a new Target...
	if (target.second) {
		target.first->second->name = name;
		target.first->second->bound_name = name;
	}

	return target.first->second;
}


// Target copy_target is the copy-constructor


void Target::touch(const std::string &name)
{
	auto target = Target::bind(name);

	target->flags |= TargetFlags::Touched;
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

// target is the existing vector to append the chain to
void
append_target_chain(std::vector<std::shared_ptr<Target>> &target, const std::vector<std::shared_ptr<Target>> &chain)
{
	std::copy(chain.begin(), chain.end(), std::back_inserter(target));
}
