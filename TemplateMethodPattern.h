#pragma once
#include <iostream>
#include <string>
namespace templates {
	class GreetingCardTemplate {
	protected:
		virtual std::string intro(const std::string& to) {
			return "Dear " + to + ",\n";
		}
		virtual std::string occasion() {
			return "Just writing to say Hi! Hope all is well with you.";
		}
		virtual std::string closing(const std::string& from) {
			return "Sincerely,\n" + from + "\n";
		}
	public:
		std::string generate(const std::string& to, const std::string& from) {
			return intro(to) + occasion() + closing(from);
		}
	};
	class BirthdayCardTemplate :public GreetingCardTemplate {
	protected:
		std::string occasion() override {
			return "Happy Birthday! Hope you have a wonderful day and lots of cake.";
		};
	};

	class NewYearsCardTemplate : public GreetingCardTemplate {
	protected:
		std::string intro(const std::string& to) override {
			return to + "!!!\n";
		}
		std::string occasion() override {
			return "Happy New Years!!! See you at the gym tomorrow!\n";
		}
	};
};