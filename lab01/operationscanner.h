#ifndef OPERATIONSCANNER_H
#define OPERATIONSCANNER_H

#include "token.h"
#include "code.h"
#include "classes.h"

class OperationScanner {
public:
	OperationScanner(Code* code);
	Token getToken();
private:
	Code* code;
	std::string token;
};

#endif // OPERATIONSCANNER_H
