#include "timestamp.h"

#include "file.h"
#include "flagset.h"
#include "path.h"

#include <sys/stat.h>

#include <iostream>
#include <unordered_map>


enum class Scanned
{
	True,
	False
};

enum class BindingFlags
{
	Init,
	NoEntry,
	Spotted,
	Missing,
	Found
};

struct Binding
{
	std::string name;
	FlagSet<BindingFlags> progress;
	Scanned state;
	time_t time;
};

static std::unordered_map<std::string, Binding> all;


static bool
file_time(const std::string &filename, time_t &time)
{
	struct stat statbuf;

	if (stat(filename.data(), &statbuf) < 0)
		return false;
	
	time = statbuf.st_mtime;
	std::cout << "file_time for " << filename << " is " << time << std::endl;
	return true;
}

void
timestamp(const std::string &target, time_t &time)
{
	path_info info;

	auto normalized_target = normalize_path(target);
	
	auto &bind = all[target];

	if (bind.name.empty())
	{
		bind.name = target;
		bind.state = Scanned::False;
		bind.progress = BindingFlags::Init;

		std::cout << "created new binding for " << target << std::endl;
	}
	else
	{
		std::cout << "found existing binding for " << target << std::endl;
	}

	if (bind.progress != BindingFlags::Init)
	{
		std::cout << "skipping scanning" << std::endl;
		goto afterScanning;
	}
	else
	{
		std::cout << "we need to scan" << std::endl;
	}

	// Not found; have to scan for it
	bind.progress = BindingFlags::NoEntry;

	std::cout << "parsing path for " << normalized_target << std::endl;
	path_parse(target, info);
	std::cout << "normalized to " << normalize_path(target) << std::endl;
	std::cout << "info.dir = " << info.dir << std::endl;

	// Scan directory if not already done so
	{
		path_info parent = info;
		parent.grist = {};
		path_parent(parent);

		auto built_path = path_build(parent);

		auto &parent_bind = all[built_path];

		if (parent_bind.name.empty())
		{
			parent_bind.name = built_path;
			parent_bind.state = Scanned::False;
			parent_bind.progress = BindingFlags::Init;

			std::cout << "parent is " << built_path << std::endl;
		}
		else
		{
			std::cout << "existing parent is " << built_path << std::endl;
		}

		if (parent_bind.state == Scanned::False)
		{
			std::cout << "running scan" << std::endl;

			// file_dirscan(buf, time_enter, bindhash);
			// time_enter: enter into our hashtable, update time, and set
			// progress to found / spotted
			// time_enter: (hashtable, target name, bool found, file time)
			file_dirscan(built_path, [](auto &entry_name)
			{
				auto &found_bind = all[entry_name];

				if (found_bind.name.empty())
				{
					found_bind.name = entry_name;
					found_bind.state = Scanned::False;
				}

				found_bind.progress = BindingFlags::Spotted;

				std::cout << "scanned: " << entry_name << std::endl;
			});

			parent_bind.state = Scanned::True;
		}
		else
		{
			std::cout << "skipping directory scan" << std::endl;
		}
	}

	// Scan archive if not already done so...
	// However, I believe this is currently unused

afterScanning:
	if (bind.progress == BindingFlags::Spotted)
	{
		if (file_time(bind.name, bind.time) == false)
		{
			bind.progress = BindingFlags::Missing;
		}
		else
		{
			bind.progress = BindingFlags::Found;
		}
	}

	time = bind.progress == BindingFlags::Found ? bind.time : 0;
}
