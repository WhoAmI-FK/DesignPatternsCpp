#pragma once
#include <iostream>
#include <string>
namespace strategy {

    class GreetingStrategy {
    public:
        virtual ~GreetingStrategy() {};
        virtual void greet(const std::string& name) = 0;
    };

    class FormalGreetingStrategy: public GreetingStrategy {
    public:
        void greet(const std::string& name) override {
            std::cout << "Good morning " << name << ", how do you do?\n";
        }
    };

    class NormalGreetingStrategy : public GreetingStrategy {
    public:
        void greet(const std::string& name) override {
            std::cout << "Hi " << name << ", how are you?\n";
        }
    };

    class InformalGreetingStrategy : public GreetingStrategy {
    public:
        void greet(const std::string& name) override {
            std::cout << "Hey " << name << ", what's up?\n";
        }
    };
    class Person {
    private:
        GreetingStrategy* greetingStrategy;
    public:
        Person(GreetingStrategy* greetingStrategy)
            : greetingStrategy(greetingStrategy)
        {

        };
        ~Person() {
            delete greetingStrategy;
        }
        void greet(const std::string& name)
        {
            greetingStrategy->greet(name);
        }
    };
};