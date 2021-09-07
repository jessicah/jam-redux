#include "path.h"

#include <unistd.h>

#include <string>
#include <iostream>
#include <vector>

bool
path_parse(const std::string &file, path_info &info)
{
	if (file.length() == 0)
	{
		return false;
	}

	info.path = file;

	std::string_view view(info.path);

	std::string_view::size_type end;

	// Look for `<grist>` and remove if found
	if (view.front() == '<')
	{
		end = view.find('>');

		if (end != view.npos)
		{
			info.grist = view.substr(0, end + 1);
			view.remove_prefix(end + 1);
		}
		else
		{
			std::cout << "no end of grist" << std::endl;
		}
	}

	
	// Look for a path with a directory prefix
	end = view.rfind('/');
	
	if (end != view.npos)
	{
		info.dir = view.substr(0, end);
		view.remove_prefix(end + 1);
	}

	// Look for a '(member)'
	end = view.find('(');

	if (end != view.npos && view.back() == ')')
	{
		info.member = view.substr(end);
		view.remove_suffix(view.size() - end);
	}

	// Look for a '.suffix'
	end = view.rfind('.');

	if (end != view.npos)
	{
		info.suffix = view.substr(end + 1);
		view.remove_suffix(view.size() - end);
	}

	// And base remains
	info.base = view;

	return true;
}

// not sure we need path_build, as we keep the original string
std::string path_build(const path_info &info)
{
	// path_parent can modify itself, so we need to do this
	std::string buffer;

	buffer.resize(info.path.length());

	if (info.grist.empty() == false)
	{
		if (info.grist.front() == '<')
		{
			buffer += info.grist;
		}
		else {
			buffer += '<';
			buffer += info.grist;
			buffer += '>';
		}
	}

	if (info.root.empty() == false
			&& info.root != "."
			&& info.root.front() != '/')
	{
		buffer += info.root;
		buffer += '/';
	}

	if (info.dir.empty() == false)
	{
		buffer += info.dir;

		if (info.base.empty() == false || info.suffix.empty() == false)
		{
			if (info.dir != "/")
			{
				buffer += '/';
			}
		}
	}

	if (info.base.empty() == false)
	{
		buffer += info.base;
	}

	if (info.suffix.empty() == false)
	{
		buffer += info.suffix;
	}

	if (info.member.empty() == false)
	{
		if (info.member.front() == '(')
		{
			buffer += info.member;
		}
		else
		{
			buffer += '(';
			buffer += info.member;
			buffer += ')';
		}
	}

	return buffer;
}

void path_parent(path_info &info)
{
	info.base = {};
	info.suffix = {};
	info.member = {};

	// should we update the internal path?
}



std::string normalize_path(std::string_view path)
{
	if (path.empty())
	{
		return {};
	}

	std::vector<std::string_view> components;

	bool is_absolute = path.front() == '/';

	while (path.empty() == false)
	{
		auto slash = path.find('/');
		bool found = slash != path.npos;

		auto component = found ? path.substr(0, slash) : path;

		if (found)
		{
			path.remove_prefix(slash + 1);
		}
		else
		{
			path = {};
		}

		if (component == "..")
		{
			components.pop_back();
		}
		else if (component == "." || component.empty())
		{
			continue;
		}
		else
		{
			components.push_back(component);
		}
	}

	std::string result;

	if (is_absolute == false)
	{
		// prepend the current working directory
		char *cwd = getcwd(NULL, 0);

		result += cwd;

		free(cwd);
	}

	for (auto &component : components)
	{
		result += '/';
		result += component;
	}

	return result;
}