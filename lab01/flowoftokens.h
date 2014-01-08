#ifndef FLOWOFTOKENS_H
#define FLOWOFTOKENS_H

#include "token.h"
#include <vector>

class FlowOfTokens : private std::vector<Token>{
public:
	FlowOfTokens();
	void addToken(Token token);
	Token getToken();
	Token showToken();
	bool IsEnd();
private:
	int CurrentToken;
	int NumberOfTokens;
};

#endif // FLOWOFTOKENS_H
