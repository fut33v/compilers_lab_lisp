#include "operationscanner.h"

OperationScanner::OperationScanner(Code* code){
	if (code != NULL){
		this->code = code;
	} else {
		std::cout<<"Error: code is NULL";
		exit(-1);
	}
	token = "";
}

Token OperationScanner::getToken(){
	token = "";
	char ch = code->ShowCh();
	int SubClass;
	switch (ch) {
		case '+': {
			SubClass = OPERATION_PLUS;
			break;
		}
		case '-': {
			SubClass = OPERATION_MINUS;
			break;
		}
		case '*': {
			SubClass = OPERATION_MULTIPLE;
			break;
		}
		case '/': {
			SubClass = OPERATION_DIVIDE;
			break;
		}
	}
	token.push_back(ch);
	code->GiveCh();
	return Token(code->getStrNum(), CLASS_OPERATION, SubClass, token, STACK_OP);
}
