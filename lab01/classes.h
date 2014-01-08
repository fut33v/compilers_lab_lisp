#ifndef CLASSES_H
#define CLASSES_H

enum Classes {
	CLASS_ERROR,
	CLASS_INTEGER,
	CLASS_FLOAT,
	CLASS_STRING,
	CLASS_OPERATION,
	CLASS_IDENTIFICATOR,
	CLASS_PARENTHESIS
};

enum OperationsSubClasses {
	OPERATION_PLUS = 1,
	OPERATION_MINUS,
	OPERATION_MULTIPLE,
	OPERATION_DIVIDE
};

enum ParenthesisSubClasses {
	PARENTHESIS_OPENING = 1,
	PARENTHESIS_CLOSING
};

enum StackSymbols {
	STACK_EXPR,
	STACK_LIST,
	STACK_LIST2,
	STACK_MEMBERS,
	STACK_MEMBERS2,
	STACK_ATOM,
	STACK_ID,
	STACK_NUM,
	STACK_FLOAT,
	STACK_STR,
	STACK_OP,
	STACK_O_PARENTHESIS,
	STACK_C_PARENTHESIS,
	STACK_BOTTOM
};

#endif // CLASSES_H