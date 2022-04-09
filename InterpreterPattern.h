#pragma once

#include <iostream>
#include <string>
namespace interpreters {
	class Expression {
	public:
		virtual int evaluate() = 0;
	};
	class OperationExpression : public Expression {
	private:
		std::string operatorSymbol;
		Expression* leftHandSide;
		Expression* rightHandSide;
	public:
		OperationExpression(const std::string& operatorSymbol,
			Expression* lhs,
			Expression* rhs) : 
			operatorSymbol(operatorSymbol),
			leftHandSide(lhs),
			rightHandSide(rhs)
		{

		}
		int evaluate() override {
			if (operatorSymbol == "+") {
				return leftHandSide->evaluate() + rightHandSide->evaluate();
			}
			else if (operatorSymbol == "-") {
				return leftHandSide->evaluate() - rightHandSide->evaluate();
			}
			else {
				std::cout << "Unrecognized operator: " << operatorSymbol;
				return 0;
			}
		}
	};
	class NumberExpression: public Expression {
	private:
		std::string numberString;
	public:
		NumberExpression(const std::string& numberString)
			: numberString(numberString)
		{

		}
		int evaluate() override {
			return std::stoi(numberString);
		}
	};
};