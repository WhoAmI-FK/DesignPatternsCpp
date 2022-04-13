#pragma once
#include <iostream>
#include <vector>
class Canvas;
namespace undos {
	class CanvasMemento {
		friend class Canvas;
		const std::vector<std::string> shapes;

	public:
		CanvasMemento(std::vector<std::string> shapes)
			: shapes(shapes)
		{

		}

	};
};

using namespace undos;
class Canvas {
	std::vector<std::string> shapes;
	std::vector<CanvasMemento*> oldStates;
public:

	~Canvas() {
		for (auto p : oldStates) {
			delete p;
		}
		oldStates.clear();
	}
	void addShape(const std::string& newShape) {
		oldStates.push_back(new CanvasMemento(shapes));
		shapes.push_back(newShape);
	}
	void undo()
	{
		CanvasMemento* previousStates = oldStates.back();
		oldStates.pop_back();
		shapes = previousStates->shapes;
		delete previousStates;
	}
	void clearAll() {
		shapes.clear();
	}
	std::vector<std::string> getShapes() {
		return shapes;
	}
};
