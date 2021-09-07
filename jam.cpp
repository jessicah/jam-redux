#include "make.h"
#include "types.h"
#include "path.h"
#include "rules.h"

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::vector<std::string> v;
	v.push_back("hello");
	v.push_back("c++");

	Target t;
	t.bound_name = "some target";

	t.depends.push_back(t);

	make(v);

	auto &t2 = Target::bind("hello");

	std::cout << t.depends[0].bound_name << std::endl;
	std::cout << t2.bound_name << std::endl;

	path_info info;

	path_parse("<x86>/a/path/to/file.txt(F=G)", info);

	std::cout << "file:   " << info.path << std::endl;
	std::cout << "grist:  " << info.grist << std::endl;
	std::cout << "dir:    " << info.dir << std::endl;
	std::cout << "member: " << info.member << std::endl;
	std::cout << "suffix: " << info.suffix << std::endl;
	std::cout << "base:   " << info.base << std::endl;

	path_parent(info);

	std::cout << "path build (parent): " << path_build(info) << std::endl;

	std::cout << "normalize: " << normalize_path("a/relative/path/../../normalized/path/to/./hello/world") << std::endl;
	std::cout << "normalize: " << normalize_path("/this/is/not/../an/absolute/path") << std::endl;
}