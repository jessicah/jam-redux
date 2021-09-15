#include "make.h"
#include "search.h"
#include "types.h"

#include <algorithm>
#include <iostream>


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


static
void
make0(std::shared_ptr<Target> &target, std::shared_ptr<Target> &parent, int depth, counts &counts, int anyhow)
{
	Targets c, d, incs; // need better names
	std::shared_ptr<Target> ptime = target;
	time_t last, leaf, hlast;
	std::string flag;
	Variables variables;

	// Step 1: Initialize
	target->fate = TargetFate::Making;

	// Step 2: Under the influence of "on target" variables,
	//         bind the target and search for headers
	
	// 2a)     Set "on target" variables
	// variables = copy_settings(target.settings);
	// push_settings(variables);

	// 2b)     Find and timestamp the target file (if it's a file)
	if (target->binding == TargetBinding::Unbound && target->flags != TargetFlags::NotFile)
	{
		target->bound_name = search(target->name, target->time);
		target->binding = target->time != 0 ? TargetBinding::Exists : TargetBinding::Missing;
	}

	// so... parent can be null...
	// Internal, NotFile header nodes have the time of their parents
	if (parent != nullptr && target->flags == TargetFlags::Internal)
	{
		ptime = parent;
	}

	// If temp file doesn't exist, but parent does, use parent
	if (parent != nullptr && target->flags == TargetFlags::Temporary
			&& target->binding == TargetBinding::Missing
			&& parent->binding != TargetBinding::Missing)
	{
		target->binding = TargetBinding::Parents;
		ptime = parent;
	}

	// 2c)     If it's a file, search for headers
	if (target->binding == TargetBinding::Exists)
	{
		// headers(target);
	}

	// 2d)     reset "on target" variables
	// popsettings(s)
	// freesettings(s)

	// Pause for a little progress reporting if debug_makeprog

	// Step 3: recursively `make0()` dependents & headers
	// 3a)     recursively `make0()` dependents
	for (auto &child : target->depends)
	{
		bool internal = target->flags == TargetFlags::Internal;

		// Warn about circular deps, except for includes,
		// which include each other a lot
		if (child->fate == TargetFate::Init)
		{
			// make0(child, ptime, depth + 1, counts, anyhow);
		}
		else if (child->fate == TargetFate::Making && internal == false)
		{
			std::cout << "warning: " << child->name << " depends on itself" << std::endl;
		}
	}

	// 3b)     recursively `make0()` internal includes node
	if (target->includes != nullptr)
	{
		// make0(*target.includes, parent, depth + 1, counts, anyhow);
	}
	
	// 3c)     add dependent's includes to our direct dependencies
	// incs : list of targets

	for (auto &child : target->depends)
	{
		if (child->includes != nullptr)
		{
			// includes = target_entry(includes, *child.includes);
		}
	}

	//target.depends = target_chain(target.depends, includes)

	// Step 4: compute time & fate
	// 4a)     we pick up dependent's time and fate

	// Step 5: sort dependents by their update time
	// if (globs.newestfirst)
	// {
	// 	make0_sort(target.depends);
	// }
}

void
make0_sort(std::vector<Target> &targets)
{
	std::sort(targets.begin(), targets.end(), [](const Target &lhs, const Target &rhs) {
		return lhs.time < rhs.time;
	});
}