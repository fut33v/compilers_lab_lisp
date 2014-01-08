#ifndef NUMBERSCANNER_H
#define NUMBERSCANNER_H

#include "code.h"
#include "token.h"
#include "classes.h"
#include "ascii.h"

class NumberScanner{
public:
	NumberScanner(Code* code);
	Token getToken();
private:
	Code* code;
	std::string token;
	enum ScannerStates{
		S_INT,
		S_FLOAT,
		S_ERROR,
		S_END
	};
	enum TableColumns{
		C_DIGITS,
		C_DOT,
		C_END
	};
	int ScanTable[2][3] =
	{//			0-9			.			' ' ) \t \n
	/*S_INT*/	{S_INT,		S_FLOAT,	S_END},
	/*S_FLOAT*/	{S_FLOAT,	S_ERROR,	S_END},
	};
};

#endif // NUMBERSCANNER_H
