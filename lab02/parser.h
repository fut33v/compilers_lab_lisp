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
	void InitializeStack();
	void InitializeProductions();
	void InitializeTable();
};

#endif // PARSER_H
