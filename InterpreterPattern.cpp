#include "InterpreterPattern.h"
using namespace interpreters;

int main()
{
	NumberExpression* five = new NumberExpression("5");
	NumberExpression* seven = new NumberExpression("7");
	OperationExpression* plus = new OperationExpression("+",
		five,seven);
	std::cout << "Five plus seven is: " << plus->evaluate() << std::endl;

	NumberExpression* thirteen = new NumberExpression("13");
	OperationExpression* complexOp = new OperationExpression("-", thirteen,
		plus);
	std::cout << "13 - (5 + 7) = " << complexOp->evaluate() << "\n";
	delete five;
	delete seven;
	delete plus;
	return 0;
}