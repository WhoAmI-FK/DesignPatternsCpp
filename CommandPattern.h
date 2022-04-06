#pragma once
#include<iostream>
#include <vector>

namespace canvas {
	class Canvas {
	private:
		std::vector<std::string> shapes;
	public:
		void addShape(const std::string& newShape) {
			shapes.push_back(newShape);
		}
		void clearAll() {
			shapes.clear();
		}
		std::vector<std::string> getShapes()
		{
			return shapes;
		}
	};
	class Command {
	public:
		virtual ~Command() {};
		virtual void execute() = 0;
	};
	class AddShapeCommand : public Command {
	private:
		std::string _shapeName;
		Canvas* _canvas;
	public:
		AddShapeCommand(const std::string& shapeName, Canvas* canvas) :
			_canvas(canvas), _shapeName(shapeName) {

		}
		void execute() {
			_canvas->addShape(_shapeName);
		}
	};
	class ClearCommand : public Command {
	private:
		Canvas* _canvas;
	public:
		ClearCommand(Canvas* canvas) :
			_canvas(canvas) {

		};
		void execute() {
			_canvas->clearAll();
		}
	};
	class Button {
	public:
		virtual ~Button() {};
		virtual void click() = 0;
	};
	class AddTriangleButton : public Button {
	private:
		Canvas* _canvas;
	public:
		AddTriangleButton(Canvas* canvas)
			:_canvas(canvas)
		{

		}
		void click() override {
			_canvas->addShape("triangle");
		}
	};
	class AddSquareButton : public Button {
	private:
		Canvas* _canvas;
	public:
		AddSquareButton(Canvas* canvas)
			:
			_canvas(canvas) {};
		void click() override {
			_canvas->addShape("square");
		}
	};
	class ClearButton : public Button {
	private:
		Canvas* _canvas;
	public:
		ClearButton(Canvas* canvas) : _canvas(canvas)
		{

		}
		void click() override {
			_canvas->clearAll();
		}
	};
};
