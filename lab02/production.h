#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <vector>

class Production : public std::vector<int>{
public:
	Production();
	void setNumber(int ProductionNumber);
	int getNumber();
private:
	int ProductionNumber;
};

#endif // PRODUCTION_H
