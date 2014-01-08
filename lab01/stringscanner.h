#ifndef STRINGSCANNER_H
#define STRINGSCANNER_H

#include "code.h"
#include "token.h"
#include "classes.h"

class StringScanner {
public:
	StringScanner(Code* code);
	Token getToken();
private:
	Code* code;
	std::string token;
};

#endif // STRINGSCANNER_H
