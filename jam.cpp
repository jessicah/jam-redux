#include "intern.h"
#include "make.h"
#include "types.h"
#include "path.h"
#include "rules.h"
#include "search.h"
#include "timestamp.h"

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "grammar/JamTokenizer.h"
#include "grammar/JamParser.h"

int main()
{
	std::vector<std::string> v;
	v.push_back("hello");
	v.push_back("c++");

	auto t = std::make_shared<Target>();

	t->bound_name = "some target";

	t->depends.push_back(t);

	make(v);

	auto t2 = Target::bind("hello");

	std::cout << t->depends[0]->bound_name << std::endl;
	std::cout << t2->bound_name << std::endl;

	path_info info;

	std::cout << "path functions::" << std::endl;
	path_parse("<x86>/a/path/to/file.txt(F=G)", info);

	std::cout << "grist:  " << info.grist << std::endl;
	std::cout << "dir:    " << info.dir << std::endl;
	std::cout << "member: " << info.member << std::endl;
	std::cout << "suffix: " << info.suffix << std::endl;
	std::cout << "base:   " << info.base << std::endl;

	path_parent(info);

	std::cout << "path build (parent): " << path_build(info) << std::endl;

	std::cout << "normalize: " << normalize_path("a/relative/path/../../normalized/path/to/./hello/world") << std::endl;
	std::cout << "normalize: " << normalize_path("/this/is/not/../an/absolute/path") << std::endl;
	
	auto view1 = intern("hello world");
	auto view3 = intern("goodbye world");
	auto view2 = intern("hello world");
	
	std::cout << "addresses: " << (void*)view1.data() << ", " << (void*)view2.data() << ", " << (void*)view3.data() << std::endl;
	
	time_t time;
	timestamp(".", time);

	auto s = search("boop.txt", time);

	std::cout << "search = " << s << ", time = " << time << std::endl;

	std::cout << ">>>>> jam parser <<<<<" << std::endl;

	TextFileStream tfs("Jamfile");

	JamTokenizer::JamTokenizer jamTokenizer;
	auto tokenizedStream = jamTokenizer.processStreamWithIgnorance(tfs);

	auto processedStream(tokenizedStream);
	
	JamParser::JamParser jamParser;
	//auto parsedStream = jamParser.parseStream(processedStream);
}