#pragma once
#include <iostream>
#include <vector>

namespace iterators {
	class NumberIterator {
	public:
		virtual ~NumberIterator() {};
		virtual int next() = 0;
		virtual bool isFinished() = 0;
	};
	class ForwardsIterator : public NumberIterator {
	private:
		int currentPosition;
		std::vector<int>& numbers;
	public:
		ForwardsIterator(std::vector<int>& numbers) :
			currentPosition(0), numbers(numbers) {

		};
		int next() override {
			int current = numbers.at(currentPosition);
			currentPosition++;
			return current;
		}
		bool isFinished() override {
			return currentPosition >= numbers.size();
		}
	};
	class BackwardsIterator : public NumberIterator {
	private:
		int currentPosition;
		std::vector<int>& numbers;
	public:
		BackwardsIterator(std::vector<int>& numbers) :
			currentPosition(0), numbers(numbers) {

		};
		int next() override {
			int current = numbers.at(numbers.size() - currentPosition - 1);
			currentPosition++;
			return current;
		}
		bool isFinished() override {
			return currentPosition >= numbers.size();
		}
	};
	class NumberCollection {
	private:
		std::vector<int> numbers;
	public:
		NumberCollection(const std::vector<int>& numbers) :
			numbers(numbers) {};
		NumberIterator* getForwardsIterator() {
			return new ForwardsIterator(numbers);
		}
		NumberIterator* getBackwardsIterator() {
			return new BackwardsIterator(numbers);
		}
	};
};
