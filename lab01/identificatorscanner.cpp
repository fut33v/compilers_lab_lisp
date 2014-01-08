#include "identificatorscanner.h"

IdentificatorScanner::IdentificatorScanner(Code* code){
	if (code != NULL){
		this->code = code;
	} else {
		std::cout<<"Error: code is NULL";
		exit(-1);
	}
	token = "";
	IdentificatorsCounter = 0;
}

Token IdentificatorScanner::getToken(){
	token = "";
	char ch = code->GiveCh();
	token += ch;
	while(1){
		ch = code->ShowCh();
		if (((int)ch >= a_ASCII && (int)ch <= z_ASCII) || ((int)ch >= A_ASCII && (int)ch <= Z_ASCII) ||
		ch == '_' || ((int)ch >= ZERO_ASCII && (int)ch <= NINE_ASCII)){
			code->GiveCh();
			token += ch;
		} else if (ch == ' ' || ch == ')' || ch == '\n' || ch == '\t'){
			IdentificatorsCounter++;
			return Token(code->getStrNum(), CLASS_IDENTIFICATOR, IdentificatorsCounter, token, STACK_ID);
		} else {
			while (1){
				ch = code->ShowCh();
				if (ch == ' ' || ch == ')' || ch == '\n' || ch == '\t'){
					break;
				}
				code->GiveCh();
				token += ch;
			}
			return Token(code->getStrNum(), CLASS_ERROR, token);
		}
	}
}
