#pragma once

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <stack>
#include <vector>

// stream
#include "ProductionStream.h"

// general dependencies
#include "Terminal.h"
#include "Parser.h"

// particular dependencies
#include "JamTokenizer.h"


namespace JamParser {
	enum class JamParserTerminalType {
		
		EOS = 0
	};

	typedef JamParserTerminalType OutputTerminalType;

	class JamParserTerminal : public Terminal<OutputTerminalType> {
	public:
		JamParserTerminal()
			: JamParserTerminal(OutputTerminalType::EOS, nullptr) { }
			// something distinguishably invalid, should never be referred to in practice if not initialized in a valid fashion

	protected:
		JamParserTerminal(OutputTerminalType type, const std::shared_ptr<Location>& occurenceLocation)
			: Terminal(type, occurenceLocation) { }
		JamParserTerminal(OutputTerminalType type, const std::string& str, const std::shared_ptr<Location>& occurenceLocation)
			: Terminal(type, str, occurenceLocation) { }
	};

	typedef JamParserTerminal OutputTerminal;
	typedef std::shared_ptr<OutputTerminal> OutputTerminalPtr;
	typedef Production OutputProduction;
	typedef std::shared_ptr<OutputProduction> OutputProductionPtr;

	class EOS : public OutputTerminal {
	public:
		EOS(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::EOS, location) { }
	};

	class Argument;
	class ArgumentsRule;
	class AssignArgumentRule;
	class Assignment;
	class BlockRule;
	class BreakRule;
	class CaseStatement;
	class ContinueRule;
	class ForRule;
	class Function;
	class IncludeRUle;
	class JamRule;
	class JamRules;
	class JumpToEofRule;
	class List;
	class ListOfLists;
	class ListOfRules;
	class LocalAssignedRules;
	class LocalRules;
	class OnArgumentRule;
	class OnRule;
	class Parameters;
	class ReturnRule;
	class RuleRule;
	class SwitchRule;
	
	class Argument : public Production {
	public:
		Argument(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "Argument"; }
	};
	class JamRule : public virtual Production {
	public:
		JamRule(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "JamRule"; }
	};
	class ArgumentsRule : public virtual Production, public JamRule {
	public:
		ArgumentsRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "ArgumentsRule"; }
	};
	class AssignArgumentRule : public virtual Production, public JamRule {
	public:
		AssignArgumentRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "AssignArgumentRule"; }
	};
	class Assignment : public Production {
	public:
		Assignment(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "Assignment"; }
	};
	class BlockRule : public virtual Production, public JamRule {
	public:
		BlockRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "BlockRule"; }
	};
	class BreakRule : public virtual Production, public JamRule {
	public:
		BreakRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "BreakRule"; }
	};
	class CaseStatement : public Production {
	public:
		CaseStatement(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "CaseStatement"; }
	};
	class ContinueRule : public virtual Production, public JamRule {
	public:
		ContinueRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "ContinueRule"; }
	};
	class ForRule : public virtual Production, public JamRule {
	public:
		ForRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "ForRule"; }
	};
	class Function : public Production {
	public:
		Function(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "Function"; }
	};
	class IncludeRUle : public virtual Production, public JamRule {
	public:
		IncludeRUle(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "IncludeRUle"; }
	};
	class JamRules : public virtual Production {
	public:
		JamRules(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "JamRules"; }
	};
	class JumpToEofRule : public virtual Production, public JamRule {
	public:
		JumpToEofRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "JumpToEofRule"; }
	};
	class List : public Production {
	public:
		List(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "List"; }
	};
	class ListOfLists : public Production {
	public:
		ListOfLists(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "ListOfLists"; }
	};
	class ListOfRules : public virtual Production, public JamRules {
	public:
		ListOfRules(const std::shared_ptr<Location>& location)
			: Production(location), JamRules(location) { }
		
		std::string stringForError() const override { return "ListOfRules"; }
	};
	class LocalAssignedRules : public virtual Production, public JamRules {
	public:
		LocalAssignedRules(const std::shared_ptr<Location>& location)
			: Production(location), JamRules(location) { }
		
		std::string stringForError() const override { return "LocalAssignedRules"; }
	};
	class LocalRules : public virtual Production, public JamRules {
	public:
		LocalRules(const std::shared_ptr<Location>& location)
			: Production(location), JamRules(location) { }
		
		std::string stringForError() const override { return "LocalRules"; }
	};
	class OnArgumentRule : public virtual Production, public JamRule {
	public:
		OnArgumentRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "OnArgumentRule"; }
	};
	class OnRule : public virtual Production, public JamRule {
	public:
		OnRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "OnRule"; }
	};
	class Parameters : public Production {
	public:
		Parameters(const std::shared_ptr<Location>& location)
			: Production(location) { }
		
		std::string stringForError() const override { return "Parameters"; }
	};
	class ReturnRule : public virtual Production, public JamRule {
	public:
		ReturnRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "ReturnRule"; }
	};
	class RuleRule : public virtual Production, public JamRule {
	public:
		RuleRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "RuleRule"; }
	};
	class SwitchRule : public virtual Production, public JamRule {
	public:
		SwitchRule(const std::shared_ptr<Location>& location)
			: Production(location), JamRule(location) { }
		
		std::string stringForError() const override { return "SwitchRule"; }
	};
	
	typedef ProductionStream<JamTokenizer::OutputTerminal> InputStream;
	typedef JamTokenizer::OutputTerminal InputType;
	typedef std::shared_ptr<JamTokenizer::OutputTerminal> InputTypePtr;

	class JamParser : public Parser<InputStream, OutputProduction> {
	public:
		JamParser() = default;

	protected:
		// helper methods
		std::string combineRaw(const std::deque<JamTokenizer::OutputTerminalPtr>& contents);
		
		// dependency machines
		
		// parsing declarations
		std::shared_ptr<Argument> parse_Argument(InputStream& is);
		std::shared_ptr<ArgumentsRule> parse_ArgumentsRule(InputStream& is);
		std::shared_ptr<AssignArgumentRule> parse_AssignArgumentRule(InputStream& is);
		std::shared_ptr<Assignment> parse_Assignment(InputStream& is);
		std::shared_ptr<BlockRule> parse_BlockRule(InputStream& is);
		std::shared_ptr<BreakRule> parse_BreakRule(InputStream& is);
		std::shared_ptr<CaseStatement> parse_CaseStatement(InputStream& is);
		std::shared_ptr<ContinueRule> parse_ContinueRule(InputStream& is);
		std::shared_ptr<ForRule> parse_ForRule(InputStream& is);
		std::shared_ptr<Function> parse_Function(InputStream& is);
		std::shared_ptr<IncludeRUle> parse_IncludeRUle(InputStream& is);
		std::shared_ptr<JamRule> parse_JamRule(InputStream& is);
		std::shared_ptr<JamRules> parse_JamRules(InputStream& is);
		std::shared_ptr<JumpToEofRule> parse_JumpToEofRule(InputStream& is);
		std::shared_ptr<List> parse_List(InputStream& is);
		std::shared_ptr<ListOfLists> parse_ListOfLists(InputStream& is);
		std::shared_ptr<ListOfRules> parse_ListOfRules(InputStream& is);
		std::shared_ptr<LocalAssignedRules> parse_LocalAssignedRules(InputStream& is);
		std::shared_ptr<LocalRules> parse_LocalRules(InputStream& is);
		std::shared_ptr<OnArgumentRule> parse_OnArgumentRule(InputStream& is);
		std::shared_ptr<OnRule> parse_OnRule(InputStream& is);
		std::shared_ptr<Parameters> parse_Parameters(InputStream& is);
		std::shared_ptr<ReturnRule> parse_ReturnRule(InputStream& is);
		std::shared_ptr<RuleRule> parse_RuleRule(InputStream& is);
		std::shared_ptr<SwitchRule> parse_SwitchRule(InputStream& is);
		std::shared_ptr<OutputProduction> parse_root(InputStream& is) override;
		
	};
};
