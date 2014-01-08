#include "parser.h"

Parser::Parser(FlowOfTokens* tokens){
	this->tokens = tokens;
	InitializeStack();
	InitializeProductions();
	InitializeTable();
	InitializeSymbolsString();
}

void Parser::InitializeStack(){
	stack.push(STACK_BOTTOM);
	stack.push(STACK_EXPR);
}

void Parser::InitializeProductions(){
	//1) <expr> -> <atom> {ID, NUM, FLOAT, STR, OP}
	Production p;
	p.setNumber(1);
	p.push_back(STACK_ATOM);
	grammar.push_back(p);
	p.clear();
	//2) <expr> -> <list> {‘(’}
	p.setNumber(2);
	p.push_back(STACK_LIST);
	grammar.push_back(p);
	p.clear();
	//3) <list> -> ‘(’ <list2> {‘(’}
	p.setNumber(3);
	p.push_back(STACK_O_PARENTHESIS);
	p.push_back(STACK_LIST2);
	grammar.push_back(p);
	p.clear();
	//4) <list2> -> <members> ‘)’ {ID, NUM, FLOAT, STR, OP}
	p.setNumber(4);
	p.push_back(STACK_MEMBERS);
	p.push_back(STACK_C_PARENTHESIS);
	grammar.push_back(p);
	p.clear();
	//5) <list2> -> ‘)’ {‘)’}
	p.setNumber(5);
	p.push_back(STACK_C_PARENTHESIS);
	grammar.push_back(p);
	p.clear();
	//6) <members> -> <expr> <members2> {ID, NUM, FLOAT, STR, OP, ‘(’}
	p.setNumber(6);
	p.push_back(STACK_EXPR);
	p.push_back(STACK_MEMBERS2);
	grammar.push_back(p);
	p.clear();
	//7) <members2> -> <members> {ID, NUM, FLOAT, STR, OP, ‘(’}
	p.setNumber(7);
	p.push_back(STACK_MEMBERS);
	grammar.push_back(p);
	p.clear();
	//8) <members2> -> 𝜀 {𝜀}
	//9) <atom> -> ID {ID}
	p.setNumber(9);
	p.push_back(STACK_ID);
	grammar.push_back(p);
	p.clear();
	//10)<atom> -> NUM {NUM}
	p.setNumber(10);
	p.push_back(STACK_NUM);
	grammar.push_back(p);
	p.clear();
	//11)<atom> -> FLOAT {FLOAT}
	p.setNumber(11);
	p.push_back(STACK_FLOAT);
	grammar.push_back(p);
	p.clear();
	//12)<atom> -> STR {STR}
	p.setNumber(12);
	p.push_back(STACK_STR);
	grammar.push_back(p);
	p.clear();
	//13)<atom> -> OP {OP}
	p.setNumber(13);
	p.push_back(STACK_OP);
	grammar.push_back(p);
	p.clear();
}

void Parser::InitializeTable(){
	table = {
		{1,	1,	1,	1,	1,	2,	0,	0},
		{0,	0,	0,	0,	0,	3,	0,	0},
		{4,	4,	4,	4,	4,	4,	5,	0},
		{6,	6,	6,	6,	6,	6,	0,	0},
		{7,	7,	7,	7,	7,	7,	0,	8},
		{9,	10,	11,	12,	13,	0,	0,	0}
	};
}

void Parser::InitializeSymbolsString(){
	StackSymbolsString = {
		"<expr>",
		"<list>",
		"<list>",
		"<list2>",
		"<members>",
		"<members2>",
		"<atom>",
		"ID",
		"NUM",
		"FLOAT",
		"STR",
		"OP",
		"(",
		")",
		"BOTTOM"
	};
}

void Parser::Parsing(){
	while (!tokens->IsEnd()){
		Token token;
		token = tokens->showToken();
		std::cout<<"Current token: "<<token.getValue()<<std::endl;
		if (token.getClassNumber()== CLASS_ERROR){
			std::cout<<"Error: wrong token";
			return;
		}
		int top = stack.top();
		std::cout<<"Stack top: "<<StackSymbolsString[top]<<std::endl;
		/*terminal case*/
		if (top > STACK_ATOM){
			if (top == token.getStackSymbol()){
				stack.pop();
				std::cout<<"Token \'"<<token.getValue()<<"\' deleted"<<std::endl;
				if (stack.top() == STACK_BOTTOM){
					std::cout<<"Passed!!!"<<std::endl;
					return;
				}
				tokens->getToken();
			} else {
				std::cout<<"Error: wrong token \'"<<token.getValue()<<"\' on string# "<<token.getStringNumber()<<std::endl;
				return;
			}
		}
		/*terminal case*/

		/*nonterminal case*/
		else if (top != STACK_BOTTOM){
			int production = table[top][TokenToColumn(&token)];
			std::cout<<"Production "<<production<<" for "<< StackSymbolsString[top] << ":" << std::endl;
			if (production > 0){
				for (auto it : grammar){
					if (it.getNumber() == production){
						std::cout<<StackSymbolsString[top]<<" -> ";
						for (auto it2 : it){
							std::cout<<StackSymbolsString[it2]<<" ";
						}
						std::cout<<std::endl;
						stack.pop();
						std::vector<int>::reverse_iterator it2;
						for (it2 = it.rbegin(); it2!= it.rend(); it2++){
							stack.push(*it2);
						}
						break;
					}
				}
			} else {
				if (table[top][COLUMN_EMPTY] != 0){
					std::cout<<"Nullify production for "<<StackSymbolsString[top] <<std::endl;
					stack.pop();
				} else {
					std::cout<<"Error: no production"<<std::endl;
					return;
				}
			}
		}
		/*nonterminal case*/
	}
}

int Parser::TokenToColumn(Token *token){
	/*ID	NUM	FLOAT	STR	OP	(	)	𝜀*/
	switch (token->getClassNumber()) {
		case CLASS_IDENTIFICATOR : {
			return COLUMN_ID;
		}
		case CLASS_NUM : {
			return COLUMN_NUM;
		}
		case CLASS_FLOAT : {
			return COLUMN_FLOAT;
		}
		case CLASS_STRING : {
			return COLUMN_STR;
		}
		case CLASS_OPERATION : {
			return COLUMN_OP;
		}
		case CLASS_PARENTHESIS : {
			if (token->getSubClassNumber() == PARENTHESIS_OPENING){
				return COLUMN_O_PARENTHESIS;
			} else {
				return COLUMN_C_PARENTHESIS;
			}
		}
	}
	return -1;
}
