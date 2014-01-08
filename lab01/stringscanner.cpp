#include "stringscanner.h"

StringScanner::StringScanner(Code* code){
	if (code != NULL){
		this->code = code;
	} else {
		std::cout<<"Error: code is NULL";
		exit(-1);
	}
	token = "";
}

Token StringScanner::getToken(){
	token = "";
	code->GiveCh();
	char ch;
	while(!code->IsEnd() && (ch=code->GiveCh())!='"'){
		token+=ch;
	}
	if (ch == '"'){
		return Token(code->getStrNum(), CLASS_STRING, token, STACK_STR);
	} else {
		return Token(code->getStrNum(), CLASS_ERROR, token);
	}
}
