#include "numberscanner.h"

NumberScanner::NumberScanner(Code* code){
	if (code != NULL){
		this->code = code;
	} else {
		std::cout<<"Error: code is NULL";
		exit(-1);
	}
	token = "";
}

Token NumberScanner::getToken(){
	token = "";
	char ch;
	int NextState=S_INT;
	int State=S_INT;
	while (NextState != S_ERROR && NextState != S_END){
		ch = code->ShowCh();
		switch(ch){
			State = NextState;
			case '.': {
				NextState = ScanTable[State][C_DOT];
				break;
			}
			case ' ': {
				NextState = ScanTable[State][C_END];
				break;
			}
			case ')': {
				NextState = ScanTable[State][C_END];
				break;
			}
			case '\t': {
				NextState = ScanTable[State][C_END];
				break;
			}
			case '\n': {
				NextState = ScanTable[State][C_END];
				break;
			}
			/*
			case '+': {
				NextState = ScanTable[State][C_END];
				break;
			}
			case '-': {
				NextState = ScanTable[State][C_END];
				break;
			}
			case '*': {
				NextState = ScanTable[State][C_END];
				break;
			}
			case '/': {
				NextState = ScanTable[State][C_END];
				break;
			}*/
			default: {
				if((int)ch >= ZERO_ASCII && (int)ch <= NINE_ASCII){
					NextState = ScanTable[State][C_DIGITS];
				} else {					
					NextState = S_ERROR;
				}
			}
		}
		if(NextState != S_ERROR && NextState != S_END){
			token += ch;
			State = NextState;
			code->GiveCh();
		}
	}
	if(NextState == S_END){
		if (State == S_INT){
			return Token(code->getStrNum(), CLASS_INTEGER, token, STACK_NUM);
		} else {
			return Token(code->getStrNum(), CLASS_FLOAT, token, STACK_FLOAT);
		}
	}
	while(ch != ' ' && ch != '\n' && ch != ')' && ch != '\t'){
		ch = code->ShowCh();
		if(ch != ' ' && ch != '\n' && ch != ')' && ch != '\t'){
			token += ch;
			code->GiveCh();
		}
	}
	return Token(code->getStrNum(), CLASS_ERROR, token);
}
