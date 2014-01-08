#include "flowoftokens.h"

FlowOfTokens::FlowOfTokens(){
	NumberOfTokens = 0;
	CurrentToken = 0;
}

void FlowOfTokens::addToken(Token token){
	push_back(token);
	NumberOfTokens++;
}

Token FlowOfTokens::getToken(){
	if (CurrentToken < NumberOfTokens){
		++CurrentToken;
	}
	if (CurrentToken == NumberOfTokens){
		return Token();
	}
	return this->at(CurrentToken);
}

Token FlowOfTokens::showToken(){
	return this->at(CurrentToken);
}

bool FlowOfTokens::IsEnd(){
   if (CurrentToken >= NumberOfTokens){
	   return true;
   } else {
	   return false;
   }
}


