#include "intern.h"

#include <string>
#include <string_view>

struct path_info
{
	void set_grist(const std::string_view &value)
	{
		grist = intern(value);
	}

	void set_root(const std::string_view &value)
	{
		root = intern(value);
	}

	void set_dir(const std::string_view &value)
	{
		dir = intern(value);
	}

	void set_base(const std::string_view &value)
	{
		base = intern(value);
	}

	void set_suffix(const std::string_view &value)
	{
		suffix = intern(value);
	}

	void set_member(const std::string_view &value)
	{
		member = intern(value);
	}

	std::string_view grist;
	std::string_view root;
	std::string_view dir;
	std::string_view base;
	std::string_view suffix;
	std::string_view member;
};

bool path_parse(const std::string &file, path_info &info);
void path_parent(path_info &info);
std::string path_build(const path_info &info);
std::string normalize_path(std::string_view path);
