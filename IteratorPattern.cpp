#include "IteratorPattern.h"
/*
using namespace iterators;

int main()
{
	std::vector<int> numbers = { 1, 2, 3, 4 ,5, 6, 7 };
	NumberCollection nc(numbers);

	NumberIterator* fi = nc.getForwardsIterator();
	NumberIterator* bi = nc.getBackwardsIterator();

	while (!fi->isFinished()) {
		std::cout << fi->next() << ", ";
	}
	std::cout << "\n";
	std::cout << "Iterating through the numbers backwards:\n";

	while (!bi->isFinished()) {
		std::cout << bi->next() << ", ";
	}
	std::cout << "\n";


	delete fi;
	delete bi;
	return 0;
}
*/