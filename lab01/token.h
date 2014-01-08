#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token{
public:
	Token(int StringNumber, int ClassNumber, int SubClassNumber, std::string Value, int StackSymbol);
	Token(int StringNumber, int ClassNumber, std::string Value, int StackSymbol);
	Token(int StringNumber, int ClassNumber, std::string Value);
	Token();
	int getStringNumber();
	int getClassNumber();
	int getSubClassNumber();
	std::string getValue();
	int getStackSymbol();
private:
	int StringNumber;
	int ClassNumber;
	int SubClassNumber;
	std::string Value;
	int StackSymbol;
};

#endif // TOKEN_H
