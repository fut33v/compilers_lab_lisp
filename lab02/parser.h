#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <iostream>
#include "production.h"
#include "lab01/classes.h"
#include "lab01/flowoftokens.h"

class Parser {
public:
	Parser(FlowOfTokens* tokens);
	void PrintProductions();
	void Parsing();
private:
	std::stack<int> stack;
	std::vector<Production> grammar;
	std::vector<std::vector<int>> table;
	FlowOfTokens* tokens;
	std::vector<std::string> StackSymbolsString;
	void InitializeStack();
	void InitializeProductions();
	void InitializeTable();
	void InitializeSymbolsString();
	int TokenToColumn(Token* token);
	/*ID	NUM	FLOAT	STR	OP	(	)	𝜀*/
	enum Columns{
		COLUMN_ID,
		COLUMN_NUM,
		COLUMN_FLOAT,
		COLUMN_STR,
		COLUMN_OP,
		COLUMN_O_PARENTHESIS,
		COLUMN_C_PARENTHESIS,
		COLUMN_EMPTY
	};
};

#endif // PARSER_H
