#include "VisitorPattern.h"

using namespace visitors;

int main()
{
	Person person("John", 40);
	Landmark landmark("Eiffel Tower", "Paris");
	Car car("Chevrolet", "Camaro");
	

	DatabaseVisitor* dbv = new DatabaseVisitor;
	TextFileVisitor* tfv = new TextFileVisitor;

	person.accept(dbv);
	landmark.accept(dbv);
	car.accept(dbv);


	person.accept(tfv);
	landmark.accept(tfv);
	car.accept(tfv);
	delete dbv;
	delete tfv;
	return 0;
}