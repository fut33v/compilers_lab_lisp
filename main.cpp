#include <iostream>

#include "lab01/code.h"
#include "lab01/token.h"
#include "lab01/flowoftokens.h"
#include "lab01/numberscanner.h"
#include "lab01/stringscanner.h"
#include "lab01/operationscanner.h"
#include "lab01/identificatorscanner.h"
#include "lab01/parenthesisscanner.h"
#include "lab01/ascii.h"

#include "lab02/parser.h"

int main(){

	/*      Lexeme scanning        */
	Code code("code.lsp");
	NumberScanner numbers(&code);
	StringScanner strings(&code);
	OperationScanner operations(&code);
	ParenthesisScanner parenthesis(&code);
	IdentificatorScanner identificators(&code);
	FlowOfTokens TokensFlow;
	while(!code.IsEnd()){
		char ch = code.ShowCh();
		if(((int)ch >= ZERO_ASCII && (int)ch <= NINE_ASCII)){
			TokensFlow.addToken(numbers.getToken());
		} else if (ch == '\"'){
			TokensFlow.addToken(strings.getToken());
		} else if(((int)ch>=a_ASCII && (int)ch<=z_ASCII) || ((int)ch>=A_ASCII && (int)ch<=Z_ASCII) || ch == '_'){
			TokensFlow.addToken(identificators.getToken());
		} else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			TokensFlow.addToken(operations.getToken());
		} else if (ch =='(' || ch == ')'){
			TokensFlow.addToken(parenthesis.getToken());
		} else if(ch == ' ' || ch == '\n' || ch == '\t'){
			code.GiveCh();
		} else {

		}
	}
	/*      Lexeme scanning        */

	/*      Lexeme scanning output */
	/*while (!TokensFlow.IsEnd()){
		Token token = TokensFlow.showToken();
		std::cout<<token.getStringNumber()<<"\tⱡ\t"<<token.getValue()<<"\tⱡ\t"<<token.getClassNumber()<<"\tⱡ\t"
				 <<token.getSubClassNumber()<<"\tⱡ\t"<<token.getStackSymbol()<<std::endl;
		TokensFlow.getToken();
	}*/
	/*      Lexeme scanning output */

	Parser parser(&TokensFlow);
	parser.Parsing();
}

