#include "path.h"
#include "types.h"
#include "timestamp.h"
#include "variable.h"


// TODO: should we look at interning returned strings?
std::string
search(const std::string &target, time_t &time)
{
	std::string buffer;
	path_info path;

	path_parse(target, path);

	// unset the grist
	path.grist = {};

	Variable var;

	if (Variable::get("LOCATE", var))
	{
		path.set_root(var.values.front());

		auto built_path = path_build(path);

		timestamp(built_path, time);

		return built_path;
	}
	else if (Variable::get("SEARCH", var))
	{
		for (auto &value : var.values)
		{
			path.set_root(value);

			auto built_path = path_build(path);

			timestamp(built_path, time);

			if (time != 0)
			{
				return built_path;
			}
		}
	}

	path.root = {};

	auto built_path = path_build(path);

	timestamp(built_path, time);

	return built_path;
}