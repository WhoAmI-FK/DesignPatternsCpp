#pragma once
#include <iostream>
namespace visitors {

    class Visitor {
    public:
        virtual void handlePerson(const std::string& name, int age) = 0;
        virtual void handleLandMark(const std::string& name, const std::string& cityName) = 0;
        virtual void handleCar(const std::string& make, const std::string& model) = 0;
    };
    class DatabaseVisitor : public Visitor {
    public:
        void handlePerson(const std::string& name, int age) override {
            std::cout << "Writng person to Database: " << name << ", " << age << "\n";
        };
         void handleLandMark(const std::string& name, const std::string& cityName) override {
            std::cout << "Writng landmark to Database: " << name << ", " << cityName << "\n";
        };
         void handleCar(const std::string& make, const std::string& model) override {
             std::cout << "Writng Car to Database: " << make << ", " << model << "\n";

         };
    };
    class TextFileVisitor : public Visitor {
    public:
        void handlePerson(const std::string& name, int age) override {
            std::cout << "Writng person to file: " << name << ", " << age << "\n";
        };
        void handleLandMark(const std::string& name, const std::string& cityName) override {
            std::cout << "Writng landmark to file: " << name << ", " << cityName << "\n";
        };
        void handleCar(const std::string& make, const std::string& model) override {
            std::cout << "Writng Car to file: " << make << ", " << model << "\n";

        };
    };
    class Person {
    private:
        std::string name;
        int age;
    public:
        Person(const std::string& name, int age) : name(name), age(age) {};
        void accept(Visitor* v) {
            v->handlePerson(name, age);
        }
    };

    class Landmark {
    private:
        std::string name;
        std::string cityName;
    public:
        Landmark(const std::string& name, const std::string& cityName) : name(name), cityName(cityName) {};
        void accept(Visitor* v) {
            v->handleLandMark(name, cityName);
        }
    };

    class Car {
    private:
        std::string make;
        std::string model;
    public:
        Car(const std::string& make, const std::string& model) : make(make), model(model) {};
        void accept(Visitor* v) {
            v->handleCar(make, model);
        }
    };

};