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
}