#include "file.h"

#include "path.h"

#include <sys/types.h>
#include <dirent.h>

#include <iostream>

void file_dirscan(const std::string &directory, const std::function<void (const std::string &)>& callback)
{
	path_info path;
	DIR *dir;
	struct dirent *entry;

	path.dir = directory.empty() ? "." : directory;

	if (directory == "/")
	{
		callback(directory);
	}

	dir = opendir(path.dir.data());

	if (dir == nullptr) return;

	while (entry = readdir(dir))
	{
		path.base = entry->d_name;

		auto built_path = path_build(path);

		callback(built_path);
	}

	closedir(dir);
}