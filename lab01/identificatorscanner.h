#ifndef IDEINTIFICATORSCANNER_H
#define IDEINTIFICATORSCANNER_H

#include "code.h"
#include "token.h"
#include "ascii.h"
#include "classes.h"

class IdentificatorScanner {
public:
	IdentificatorScanner(Code* code);
	Token getToken();
private:
	Code* code;
	std::string token;
	int IdentificatorsCounter;
};

#endif // IDEINTIFICATORSCANNER_H
