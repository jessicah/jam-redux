#pragma once

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <stack>
#include <vector>

// stream
#include "RawStream.h"

// general dependencies
#include "Terminal.h"
#include "Machine.h"

// particular dependencies


namespace JamTokenizer {
	enum class JamTokenizerTerminalType {
		Actions = 1,
		And = 2,
		Append = 3,
		Bind = 4,
		Break = 5,
		Case = 6,
		Colon = 7,
		Continue = 8,
		Default = 9,
		DefaultAssign = 10,
		Else = 11,
		Equals = 12,
		Existing = 13,
		For = 14,
		GreaterOrEqual = 15,
		GreaterThan = 16,
		If = 17,
		Ignore = 18,
		In = 19,
		Include = 20,
		JumpToEof = 21,
		LeftBrace = 22,
		LeftBracket = 23,
		LeftParen = 24,
		LessOrEqual = 25,
		LessThan = 26,
		Local = 27,
		LogicalAnd = 28,
		LogicalOr = 29,
		Maxline = 30,
		Not = 31,
		NotEqual = 32,
		On = 33,
		Or = 34,
		Piecemeal = 35,
		Quietly = 36,
		Return = 37,
		RightBrace = 38,
		RightBracket = 39,
		RightParen = 40,
		Rule = 41,
		SemiColon = 42,
		String = 43,
		Switch = 44,
		Together = 45,
		Update = 46,
		While = 47,
		WhiteSpace = 48,
		
		EOS = 0
	};

	typedef JamTokenizerTerminalType OutputTerminalType;

	class JamTokenizerTerminal : public Terminal<OutputTerminalType> {
	public:
		JamTokenizerTerminal()
			: JamTokenizerTerminal(OutputTerminalType::EOS, nullptr) { }
			// something distinguishably invalid, should never be referred to in practice if not initialized in a valid fashion

	protected:
		JamTokenizerTerminal(OutputTerminalType type, const std::shared_ptr<Location>& occurenceLocation)
			: Terminal(type, occurenceLocation) { }
		JamTokenizerTerminal(OutputTerminalType type, const std::string& str, const std::shared_ptr<Location>& occurenceLocation)
			: Terminal(type, str, occurenceLocation) { }
	};

	typedef JamTokenizerTerminal OutputTerminal;
	typedef std::shared_ptr<OutputTerminal> OutputTerminalPtr;
	typedef OutputTerminal OutputProduction;
	typedef std::shared_ptr<OutputProduction> OutputProductionPtr;

	class EOS : public OutputTerminal {
	public:
		EOS(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::EOS, location) { }
	};
	
	class Actions;
	class And;
	class Append;
	class Bind;
	class Break;
	class Case;
	class Colon;
	class Continue;
	class Default;
	class DefaultAssign;
	class Else;
	class Equals;
	class Existing;
	class For;
	class GreaterOrEqual;
	class GreaterThan;
	class If;
	class Ignore;
	class In;
	class Include;
	class JumpToEof;
	class LeftBrace;
	class LeftBracket;
	class LeftParen;
	class LessOrEqual;
	class LessThan;
	class Local;
	class LogicalAnd;
	class LogicalOr;
	class Maxline;
	class Not;
	class NotEqual;
	class On;
	class Or;
	class Piecemeal;
	class Quietly;
	class Return;
	class RightBrace;
	class RightBracket;
	class RightParen;
	class Rule;
	class SemiColon;
	class String;
	class Switch;
	class Together;
	class Update;
	class While;
	class WhiteSpace;
	
	class Actions : public OutputTerminal {
	public:
		Actions(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Actions, location) { }
	};
	class And : public OutputTerminal {
	public:
		And(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::And, location) { }
	};
	class Append : public OutputTerminal {
	public:
		Append(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Append, location) { }
	};
	class Bind : public OutputTerminal {
	public:
		Bind(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Bind, location) { }
	};
	class Break : public OutputTerminal {
	public:
		Break(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Break, location) { }
	};
	class Case : public OutputTerminal {
	public:
		Case(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Case, location) { }
	};
	class Colon : public OutputTerminal {
	public:
		Colon(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Colon, location) { }
	};
	class Continue : public OutputTerminal {
	public:
		Continue(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Continue, location) { }
	};
	class Default : public OutputTerminal {
	public:
		Default(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Default, location) { }
	};
	class DefaultAssign : public OutputTerminal {
	public:
		DefaultAssign(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::DefaultAssign, location) { }
	};
	class Else : public OutputTerminal {
	public:
		Else(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Else, location) { }
	};
	class Equals : public OutputTerminal {
	public:
		Equals(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Equals, location) { }
	};
	class Existing : public OutputTerminal {
	public:
		Existing(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Existing, location) { }
	};
	class For : public OutputTerminal {
	public:
		For(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::For, location) { }
	};
	class GreaterOrEqual : public OutputTerminal {
	public:
		GreaterOrEqual(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::GreaterOrEqual, location) { }
	};
	class GreaterThan : public OutputTerminal {
	public:
		GreaterThan(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::GreaterThan, location) { }
	};
	class If : public OutputTerminal {
	public:
		If(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::If, location) { }
	};
	class Ignore : public OutputTerminal {
	public:
		Ignore(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Ignore, location) { }
	};
	class In : public OutputTerminal {
	public:
		In(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::In, location) { }
	};
	class Include : public OutputTerminal {
	public:
		Include(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Include, location) { }
	};
	class JumpToEof : public OutputTerminal {
	public:
		JumpToEof(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::JumpToEof, location) { }
	};
	class LeftBrace : public OutputTerminal {
	public:
		LeftBrace(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LeftBrace, location) { }
	};
	class LeftBracket : public OutputTerminal {
	public:
		LeftBracket(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LeftBracket, location) { }
	};
	class LeftParen : public OutputTerminal {
	public:
		LeftParen(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LeftParen, location) { }
	};
	class LessOrEqual : public OutputTerminal {
	public:
		LessOrEqual(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LessOrEqual, location) { }
	};
	class LessThan : public OutputTerminal {
	public:
		LessThan(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LessThan, location) { }
	};
	class Local : public OutputTerminal {
	public:
		Local(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Local, location) { }
	};
	class LogicalAnd : public OutputTerminal {
	public:
		LogicalAnd(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LogicalAnd, location) { }
	};
	class LogicalOr : public OutputTerminal {
	public:
		LogicalOr(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::LogicalOr, location) { }
	};
	class Maxline : public OutputTerminal {
	public:
		Maxline(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Maxline, location) { }
	};
	class Not : public OutputTerminal {
	public:
		Not(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Not, location) { }
	};
	class NotEqual : public OutputTerminal {
	public:
		NotEqual(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::NotEqual, location) { }
	};
	class On : public OutputTerminal {
	public:
		On(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::On, location) { }
	};
	class Or : public OutputTerminal {
	public:
		Or(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Or, location) { }
	};
	class Piecemeal : public OutputTerminal {
	public:
		Piecemeal(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Piecemeal, location) { }
	};
	class Quietly : public OutputTerminal {
	public:
		Quietly(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Quietly, location) { }
	};
	class Return : public OutputTerminal {
	public:
		Return(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Return, location) { }
	};
	class RightBrace : public OutputTerminal {
	public:
		RightBrace(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::RightBrace, location) { }
	};
	class RightBracket : public OutputTerminal {
	public:
		RightBracket(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::RightBracket, location) { }
	};
	class RightParen : public OutputTerminal {
	public:
		RightParen(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::RightParen, location) { }
	};
	class Rule : public OutputTerminal {
	public:
		Rule(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Rule, location) { }
	};
	class SemiColon : public OutputTerminal {
	public:
		SemiColon(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::SemiColon, location) { }
	};
	class String : public OutputTerminal {
	public:
		String(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::String, location) { }
	};
	class Switch : public OutputTerminal {
	public:
		Switch(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Switch, location) { }
	};
	class Together : public OutputTerminal {
	public:
		Together(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Together, location) { }
	};
	class Update : public OutputTerminal {
	public:
		Update(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::Update, location) { }
	};
	class While : public OutputTerminal {
	public:
		While(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::While, location) { }
	};
	class WhiteSpace : public OutputTerminal {
	public:
		WhiteSpace(const std::shared_ptr<Location>& location)
			: OutputTerminal(OutputTerminalType::WhiteSpace, location) { }
	};
	
	using State = size_t;

	typedef RawStream InputStream;
	typedef RawTerminal InputTerminal;
	typedef std::shared_ptr<RawTerminal> InputTerminalPtr;

	class JamTokenizer;
	typedef void (JamTokenizer::* ActionMethodPointer)(size_t, const std::deque<InputTerminalPtr>&, const std::shared_ptr<Location>&);
	class JamTokenizer : public Machine<InputStream, OutputProduction> {
	public:
		JamTokenizer()
			: m_currentState(0) { }

		std::shared_ptr<OutputProduction> apply(InputStream& rs) override;

		bool lastApplicationSuccessful() const override { return m_stateFinality[m_currentState]; }
		void reset() override;

	private:
		// state-switching internals
		State m_currentState;
		static std::vector<State> m_stateMap[177][256];
		static bool m_stateFinality[177];
		static std::vector<void (JamTokenizer::*)(size_t, const std::deque<InputTerminalPtr>&, const std::shared_ptr<Location>&)> m_transitionActions[177][256];
		static void (JamTokenizer::* m_stateActions[177])(size_t, const std::deque<InputTerminalPtr>&, const std::shared_ptr<Location>&);

		// raw-capture internals
		std::stack<size_t> m_captureStack;

		// helper methods
		

		// dependency machines
		
		// action contexts
		std::shared_ptr<OutputProduction> m_token;
		std::shared_ptr<Actions> m_token__Actions;
		std::shared_ptr<And> m_token__And;
		std::shared_ptr<Append> m_token__Append;
		std::shared_ptr<Bind> m_token__Bind;
		std::shared_ptr<Break> m_token__Break;
		std::shared_ptr<Case> m_token__Case;
		std::shared_ptr<Colon> m_token__Colon;
		std::shared_ptr<Continue> m_token__Continue;
		std::shared_ptr<Default> m_token__Default;
		std::shared_ptr<DefaultAssign> m_token__DefaultAssign;
		std::shared_ptr<Else> m_token__Else;
		std::shared_ptr<Equals> m_token__Equals;
		std::shared_ptr<Existing> m_token__Existing;
		std::shared_ptr<For> m_token__For;
		std::shared_ptr<GreaterOrEqual> m_token__GreaterOrEqual;
		std::shared_ptr<GreaterThan> m_token__GreaterThan;
		std::shared_ptr<If> m_token__If;
		std::shared_ptr<Ignore> m_token__Ignore;
		std::shared_ptr<In> m_token__In;
		std::shared_ptr<Include> m_token__Include;
		std::shared_ptr<JumpToEof> m_token__JumpToEof;
		std::shared_ptr<LeftBrace> m_token__LeftBrace;
		std::shared_ptr<LeftBracket> m_token__LeftBracket;
		std::shared_ptr<LeftParen> m_token__LeftParen;
		std::shared_ptr<LessOrEqual> m_token__LessOrEqual;
		std::shared_ptr<LessThan> m_token__LessThan;
		std::shared_ptr<Local> m_token__Local;
		std::shared_ptr<LogicalAnd> m_token__LogicalAnd;
		std::shared_ptr<LogicalOr> m_token__LogicalOr;
		std::shared_ptr<Maxline> m_token__Maxline;
		std::shared_ptr<Not> m_token__Not;
		std::shared_ptr<NotEqual> m_token__NotEqual;
		std::shared_ptr<On> m_token__On;
		std::shared_ptr<Or> m_token__Or;
		std::shared_ptr<Piecemeal> m_token__Piecemeal;
		std::shared_ptr<Quietly> m_token__Quietly;
		std::shared_ptr<Return> m_token__Return;
		std::shared_ptr<RightBrace> m_token__RightBrace;
		std::shared_ptr<RightBracket> m_token__RightBracket;
		std::shared_ptr<RightParen> m_token__RightParen;
		std::shared_ptr<Rule> m_token__Rule;
		std::shared_ptr<SemiColon> m_token__SemiColon;
		std::shared_ptr<String> m_token__String;
		std::shared_ptr<Switch> m_token__Switch;
		std::shared_ptr<Together> m_token__Together;
		std::shared_ptr<Update> m_token__Update;
		std::shared_ptr<While> m_token__While;
		std::shared_ptr<WhiteSpace> m_token__WhiteSpace;
		
		// actions
		void actionRegister1(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister2(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister3(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister4(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister5(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister6(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister7(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister8(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister9(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister10(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister11(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister12(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister13(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister14(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister15(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister16(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister17(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister18(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister19(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister20(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister21(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister22(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister23(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister24(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister25(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister26(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister27(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister28(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister29(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister30(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister31(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister32(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister33(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister34(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister35(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister36(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister37(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister38(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister39(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister40(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister41(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister42(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister43(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister44(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister45(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister46(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister47(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister48(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister49(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister50(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister51(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister52(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister53(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister54(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister55(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister56(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister57(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister58(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister59(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister60(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister61(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister62(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister63(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister64(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister65(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister66(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister67(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister68(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister69(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister70(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister71(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister72(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister73(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister74(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister75(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister76(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister77(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister78(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister79(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister80(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister81(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister82(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister83(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister84(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister85(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister86(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister87(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister88(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister89(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister90(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister91(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister92(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister93(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister94(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister95(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister96(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister97(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister98(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister99(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister100(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister101(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister102(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister103(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister104(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister105(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister106(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		void actionRegister107(size_t position, const std::deque<InputTerminalPtr>& input, const std::shared_ptr<Location>& location);
		
	};
};
