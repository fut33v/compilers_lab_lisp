#include "token.h"

Token::Token(int StringNumber, int ClassNumber, int SubClassNumber, std::string Value, int StackSymbol){
	this->StringNumber = StringNumber;
	this->ClassNumber = ClassNumber;
	this->SubClassNumber = SubClassNumber;
	this->Value = Value;
	this->StackSymbol = StackSymbol;
}

Token::Token(int StringNumber, int ClassNumber, std::string Value, int StackSymbol){
	this->StringNumber = StringNumber;
	this->ClassNumber = ClassNumber;
	this->SubClassNumber = 0;
	this->Value = Value;
	this->StackSymbol = StackSymbol;
}

Token::Token(int StringNumber, int ClassNumber, std::string Value){
	this->StringNumber = StringNumber;
	this->ClassNumber = ClassNumber;
	this->SubClassNumber = 0;
	this->Value = Value;
	this->StackSymbol = -1;
}

Token::Token(){
	this->StringNumber = 0;
	this->ClassNumber = 0;
	this->SubClassNumber = 0;
	this->Value = "";
	this->StackSymbol = -1;
}

int Token::getClassNumber(){
	return ClassNumber;
}

int Token::getStringNumber(){
	return StringNumber;
}

int Token::getSubClassNumber(){
	return SubClassNumber;
}

std::string Token::getValue(){
	return Value;
}

int Token::getStackSymbol(){
	return StackSymbol;
}
