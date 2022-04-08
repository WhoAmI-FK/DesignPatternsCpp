#include "CommandPattern.h"
// test of the pattern
/*
using namespace canvas;
int main() {
	Canvas* canvas = new Canvas;
	Button* addTriangleButton = new Button(new AddShapeCommand(
	"triangle",canvas
	));
	Button* addSquareButton = new Button(new AddShapeCommand(
	"square", canvas
	));
	Button* clearButton = new Button(new ClearCommand(canvas));
	addTriangleButton->click();
	std::cout << "Current canvas state: " <<
		vectorToString(canvas->getShapes()) << "\n";
	addSquareButton->click();
	addSquareButton->click();
	addTriangleButton->click();
	std::cout << "Current canvas state: " <<
		vectorToString(canvas->getShapes()) << "\n";
	clearButton->click();
	std::cout << "Current canvas state: " <<
		vectorToString(canvas->getShapes()) << "\n";
	delete canvas;
	return 0;
}
*/