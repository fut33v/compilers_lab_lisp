#include "parenthesisscanner.h"

ParenthesisScanner::ParenthesisScanner(Code* code){
	if (code != NULL){
		this->code = code;
	} else {
		std::cout<<"Error: code is NULL";
		exit(-1);
	}
	token = "";
}

Token ParenthesisScanner::getToken(){
	token = "";
	char ch = code->ShowCh();
	int SubClass;
	switch (ch) {
		case '(': {
			SubClass = PARENTHESIS_OPENING;
			break;
		}
		case ')': {
			SubClass = PARENTHESIS_CLOSING;
			break;
		}
	}
	token.push_back(ch);
	code->GiveCh();
	if (SubClass == PARENTHESIS_OPENING){
		return Token(code->getStrNum(), CLASS_PARENTHESIS, SubClass, token, STACK_O_PARENTHESIS);
	} else {
		return Token(code->getStrNum(), CLASS_PARENTHESIS, SubClass, token, STACK_C_PARENTHESIS);
	}
}
