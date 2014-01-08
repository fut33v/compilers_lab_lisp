#ifndef PARENTHESISSCANNER_H
#define PARENTHESISSCANNER_H

#include "token.h"
#include "code.h"
#include "classes.h"

class ParenthesisScanner
{
public:
	ParenthesisScanner(Code* code);
	Token getToken();
private:
	Code* code;
	std::string token;
};

#endif // PARENTHESISSCANNER_H
