#include "flagset.h"

#include <array>
#include <forward_list>
#include <unordered_map>
#include <string>
#include <vector>

#pragma once

#define MAXLINE 120000

typedef struct {
	int		temp;
	int		updating;
	int		cant_find;
	int		cant_make;
	int		targets;
	int		made;
} counts;

enum class TargetFlags {
	Temporary,
	NoCare,
	NotFile,
	Always,
	Leaves,
	NoUpdate,
	Touched,
	Internal
};

enum class TargetBinding {
	Unbound,
	Missing,
	Parents,
	Exists
};

enum class TargetFate {
	Init,
	Making,
	Stable,
	Newer,
	Spoil,
	IsTemporary,
	Build,
	Touched,
	Missing,
	NeedTemporary,
	Outdated,
	Update,
	Broken,
	CantFind,
	CantMake
};

enum class TargetMake {
	Init,
	OnStack,
	Active,
	Running,
	Done
};

enum class RuleFlags {
	Updated,
	Together,
	Ignore,
	Quietly,
	Piecemeal,
	Existing,
	MaxLine
};

class Variable
{
public:
	Variable(std::string &name, std::string &value) : name(name), value(value) {};

	std::string name;
	std::string value;
};

typedef std::vector<Variable> Variables;


class Rule
{
public:
	std::string name;
	// a procedure .. currently the parse tree from Jamfiles
	std::string actions; // not entirely sure here
	std::vector<std::string> bindings; // maybe?
	std::vector<std::string> parameters;
	FlagSet<RuleFlags> flags;

	static Rule& bind(const std::string &name);
private:
	static std::unordered_map<std::string, Rule> rules;
};

class Target;

typedef std::vector<Target> Targets;

class Action
{
public:
	Rule rule;
	Targets targets; // needs to be of type Target...
	Targets sources; // needs to be of type Target...

	bool running;
	TargetMake status;
};

typedef std::vector<Action> Actions;

class Target
{
public:
	Target() { }

	Target(const Target &from)
		: name(from.name), bound_name(from.bound_name)
	{
		flags = TargetFlags::NotFile | TargetFlags::Internal;
	}	

	void touch()
	{
		flags |= TargetFlags::Touched;
	}

	static Target& bind(const std::string &name);
	static void touch(const std::string &name);

	std::string name;
	std::string bound_name;

	Actions actions;
	Variables variables;

	FlagSet<TargetFlags> flags;
	TargetBinding binding;

	std::vector<Target> depends;
	std::vector<Target> includes;

	time_t time;
	time_t leaf;
	
	TargetFate fate;
	TargetMake progress;

	int status;
	int async_count;

	std::vector<Target> parents;

	std::string commands;
private:
	static std::unordered_map<std::string, Target> targets;
};

class Command
{
public:
	Rule rule; // or do we want a list?
	std::vector<std::string> shell; // maybe array is better?
	std::vector<std::string> targets;
	std::vector<std::string> sources;
	std::array<char, MAXLINE> buffer;
};
