#include <string>
#include <string_view>

struct path_info
{
	std::string path;

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

// path_build
// path_parse
// path_parent

// normalize_path
