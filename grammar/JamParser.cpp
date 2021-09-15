#pragma once

#include <sstream>

#include "JamParser.h"

namespace JamParser {
	std::shared_ptr<Argument> JamParser::parse_Argument(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "Argument";
		std::shared_ptr<Argument> typeFormingStatement = std::make_shared<Argument>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"LeftBracket\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Function(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | On)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::RightBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"RightBracket\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\", or \"LeftBracket\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<ArgumentsRule> JamParser::parse_ArgumentsRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "ArgumentsRule";
		std::shared_ptr<ArgumentsRule> typeFormingStatement = std::make_shared<ArgumentsRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_ListOfLists(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<AssignArgumentRule> JamParser::parse_AssignArgumentRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "AssignArgumentRule";
		std::shared_ptr<AssignArgumentRule> typeFormingStatement = std::make_shared<AssignArgumentRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Assignment(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(Equals | Append | DefaultAssign | Default)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<Assignment> JamParser::parse_Assignment(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "Assignment";
		std::shared_ptr<Assignment> typeFormingStatement = std::make_shared<Assignment>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Equals\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Append\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"DefaultAssign\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Default\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Equals\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Equals\", or \"Append\", or \"DefaultAssign\", or \"Default\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<BlockRule> JamParser::parse_BlockRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "BlockRule";
		std::shared_ptr<BlockRule> typeFormingStatement = std::make_shared<BlockRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"LeftBrace\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_JamRules(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::RightBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"RightBrace\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"LeftBrace\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<BreakRule> JamParser::parse_BreakRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "BreakRule";
		std::shared_ptr<BreakRule> typeFormingStatement = std::make_shared<BreakRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Break\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Break\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<CaseStatement> JamParser::parse_CaseStatement(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "CaseStatement";
		std::shared_ptr<CaseStatement> typeFormingStatement = std::make_shared<CaseStatement>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Case>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Case>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Case\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Colon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Colon\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_JamRules(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local)\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Case\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<ContinueRule> JamParser::parse_ContinueRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "ContinueRule";
		std::shared_ptr<ContinueRule> typeFormingStatement = std::make_shared<ContinueRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Continue\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Continue\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<ForRule> JamParser::parse_ForRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "ForRule";
		std::shared_ptr<ForRule> typeFormingStatement = std::make_shared<ForRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"For\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::In>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"In\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"LeftBrace\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_JamRules(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::RightBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"RightBrace\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"For\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<Function> JamParser::parse_Function(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "Function";
		std::shared_ptr<Function> typeFormingStatement = std::make_shared<Function>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_ListOfLists(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)))) {
			if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"On\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_ListOfLists(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)))) {
			if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"On\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Return\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else {
			error("Unexpected token sequence \"" + is.peek(0)->stringForError() + " " + is.peek(1)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\", or \"On (String | LeftBracket)\", or \"On (String | LeftBracket)\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<IncludeRUle> JamParser::parse_IncludeRUle(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "IncludeRUle";
		std::shared_ptr<IncludeRUle> typeFormingStatement = std::make_shared<IncludeRUle>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Include\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Include\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<JamRule> JamParser::parse_JamRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "JamRule";
		std::shared_ptr<JamRule> typeFormingStatement = std::make_shared<JamRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))))) {
			return parse_ArgumentsRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+1))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+3))) {
			return parse_AssignArgumentRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0))) {
			return parse_BlockRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0))) {
			return parse_BreakRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0))) {
			return parse_ContinueRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0))) {
			return parse_ForRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0))) {
			return parse_IncludeRUle(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0))) {
			return parse_JumpToEofRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
			return parse_OnArgumentRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
			return parse_OnRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0))) {
			return parse_ReturnRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0))) {
			return parse_RuleRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
			return parse_SwitchRule(is);
		} else {
			error("Unexpected token sequence \"" + is.peek(0)->stringForError() + " " + is.peek(1)->stringForError() + " " + is.peek(2)->stringForError() + " " + is.peek(3)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String String | LeftBracket (String String | LeftBracket (String | LeftBracket | On) | On (String | LeftBracket)))\", or \"(String (Equals | Append | DefaultAssign | Default) | LeftBracket String String String)\", or \"LeftBrace\", or \"Break\", or \"Continue\", or \"For\", or \"Include\", or \"JumpToEof\", or \"(String | LeftBracket)\", or \"On\", or \"Return\", or \"Rule\", or \"Switch\"");
		}
		
		return nullptr; // to suppress the warning
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<JamRules> JamParser::parse_JamRules(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "JamRules";
		std::shared_ptr<JamRules> typeFormingStatement = std::make_shared<JamRules>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
			return parse_ListOfRules(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
			return parse_LocalAssignedRules(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
			return parse_LocalRules(is);
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch)\", or \"Local\", or \"Local\"");
		}
		
		return nullptr; // to suppress the warning
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<JumpToEofRule> JamParser::parse_JumpToEofRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "JumpToEofRule";
		std::shared_ptr<JumpToEofRule> typeFormingStatement = std::make_shared<JumpToEofRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"JumpToEof\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"JumpToEof\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<List> JamParser::parse_List(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "List";
		std::shared_ptr<List> typeFormingStatement = std::make_shared<List>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_List(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<ListOfLists> JamParser::parse_ListOfLists(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "ListOfLists";
		std::shared_ptr<ListOfLists> typeFormingStatement = std::make_shared<ListOfLists>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Colon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Colon\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_ListOfLists(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
		} else {
			error("Unexpected token sequence \"" + is.peek(0)->stringForError() + " " + is.peek(1)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String String\", or \"String String\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<ListOfRules> JamParser::parse_ListOfRules(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "ListOfRules";
		std::shared_ptr<ListOfRules> typeFormingStatement = std::make_shared<ListOfRules>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_JamRule(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch)\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch)\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<LocalAssignedRules> JamParser::parse_LocalAssignedRules(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "LocalAssignedRules";
		std::shared_ptr<LocalAssignedRules> typeFormingStatement = std::make_shared<LocalAssignedRules>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Local\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Equals\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_JamRules(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local)\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Local\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<LocalRules> JamParser::parse_LocalRules(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "LocalRules";
		std::shared_ptr<LocalRules> typeFormingStatement = std::make_shared<LocalRules>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Local\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_JamRules(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local)\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Local\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<OnArgumentRule> JamParser::parse_OnArgumentRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "OnArgumentRule";
		std::shared_ptr<OnArgumentRule> typeFormingStatement = std::make_shared<OnArgumentRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"On\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Assignment(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(Equals | Append | DefaultAssign | Default)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<OnRule> JamParser::parse_OnRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "OnRule";
		std::shared_ptr<OnRule> typeFormingStatement = std::make_shared<OnRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"On\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_JamRule(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch)\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"On\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<Parameters> JamParser::parse_Parameters(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "Parameters";
		std::shared_ptr<Parameters> typeFormingStatement = std::make_shared<Parameters>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
		} else if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2))) {
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Colon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Colon\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Parameters(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
		} else {
			error("Unexpected token sequence \"" + is.peek(0)->stringForError() + " " + is.peek(1)->stringForError() + " " + is.peek(2)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String (String | LeftBracket) | LeftBracket (String String | LeftBracket (String | LeftBracket | On) | On (String | LeftBracket)))\", or \"(String | LeftBracket String String)\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<ReturnRule> JamParser::parse_ReturnRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "ReturnRule";
		std::shared_ptr<ReturnRule> typeFormingStatement = std::make_shared<ReturnRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Return\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_List(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::SemiColon>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"SemiColon\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Return\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<RuleRule> JamParser::parse_RuleRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "RuleRule";
		std::shared_ptr<RuleRule> typeFormingStatement = std::make_shared<RuleRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Rule\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_Argument(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0))) {
				{
					unsigned long counter = 1;
					while(counter > 0 && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)))) {
						auto payload = parse_Parameters(is);
						--counter;
					}
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"LeftBrace\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_JamRules(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local)\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::RightBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"RightBrace\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Rule\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<SwitchRule> JamParser::parse_SwitchRule(InputStream& is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "SwitchRule";
		std::shared_ptr<SwitchRule> typeFormingStatement = std::make_shared<SwitchRule>(productionStartLocation);
		size_t cumulativePeekCorrection = 0;
		
		if(std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
			if(std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Switch\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = parse_List(is);
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"String\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"LeftBrace\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::Case>(is.peek(cumulativePeekCorrection+0))) {
				while(std::dynamic_pointer_cast<JamTokenizer::Case>(is.peek(cumulativePeekCorrection+0))) {
					auto payload = parse_CaseStatement(is);
				}
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Case\"");
			}
			
			if(std::dynamic_pointer_cast<JamTokenizer::RightBrace>(is.peek(cumulativePeekCorrection+0))) {
				auto payload = is.consume();
			} else {
				error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"RightBrace\"");
			}
		} else {
			error("Unexpected token \"" + is.peek(0)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"Switch\"");
		}
		
		return typeFormingStatement;
	}
	
	std::shared_ptr<OutputProduction> JamParser::parse_root(InputStream & is) {
		auto productionStartLocation = is.peek(0)->location()->clone();
		const std::string typeFormingStatementName = "root";
		size_t cumulativePeekCorrection = 0;
		if(std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)))) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::In>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)))) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)))) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)))) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2))) {
			return parse_JamRule(is);
		} else if(std::dynamic_pointer_cast<JamTokenizer::Local>(is.peek(cumulativePeekCorrection+0)) || std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::Equals>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Append>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::DefaultAssign>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Default>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)))) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::In>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBrace>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Break>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Continue>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::For>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Include>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::JumpToEof>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+1))) || std::dynamic_pointer_cast<JamTokenizer::Return>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) || std::dynamic_pointer_cast<JamTokenizer::Rule>(is.peek(cumulativePeekCorrection+0)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2))) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+1)) && (std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::LeftBracket>(is.peek(cumulativePeekCorrection+2)) || std::dynamic_pointer_cast<JamTokenizer::On>(is.peek(cumulativePeekCorrection+2)))) || std::dynamic_pointer_cast<JamTokenizer::Switch>(is.peek(cumulativePeekCorrection+0)) && std::dynamic_pointer_cast<JamTokenizer::String>(is.peek(cumulativePeekCorrection+1))) {
			return parse_JamRules(is);
		} else {
			error("Unexpected token sequence \"" + is.peek(0)->stringForError() + " " + is.peek(1)->stringForError() + " " + is.peek(2)->stringForError() + "\" encountered at " + is.peek(0)->locationString() + " in construction for '" + typeFormingStatementName + "'; expected \"(String (String String | Equals String | Append String | DefaultAssign String | Default Equals | On String) | LeftBracket (String String | LeftBracket (String | LeftBracket | On) | On (String | LeftBracket)) | LeftBrace (String (String | Equals | Append | DefaultAssign | Default | On) | LeftBracket (String | LeftBracket | On) | LeftBrace (String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch | Local) | Break String | Continue String | For (String | LeftBracket) | Include String | JumpToEof String | On (String | LeftBracket) | Return String | Rule (String | LeftBracket) | Switch String | Local String) | Break String String | Continue String String | For (String In | LeftBracket (String | LeftBracket | On)) | Include String String | JumpToEof String String | On (String (String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch) | LeftBracket (String | LeftBracket | On)) | Return String String | Rule (String (String | LeftBracket) | LeftBracket (String | LeftBracket | On)) | Switch String String)\", or \"(Local | String String String | LeftBracket String String | LeftBrace (String (String | Equals | Append | DefaultAssign | Default | On) | Equals | Append | DefaultAssign | Default | On (String | LeftBracket)) | Break String | Continue String | For In | Include String | JumpToEof String | On (String (String | LeftBracket | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch) | LeftBracket (String | LeftBracket | On) | LeftBrace | Break | Continue | For | Include | JumpToEof | On | Return | Rule | Switch) | Return String | Rule (String (String | LeftBracket) | LeftBracket (String | LeftBracket | On)) | Switch String)\"");
			return nullptr; // to suppress the warning
		}
	}
	
	
	// helper methods
	std::string JamParser::combineRaw(const std::deque<JamTokenizer::OutputTerminalPtr>& contents) {
		std::stringstream ss;
		for(const auto& element : contents) {
			ss << element->raw;
		}
		 return ss.str();
	}
	
}