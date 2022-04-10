#pragma once
#include <iostream>

namespace state {
    class State {
    public:
        virtual std::string getDescription() = 0;
        virtual State* getNextState() = 0;
    };

    class PurchasedState : public State {
    private:
        State* nextState;
    public:
        PurchasedState(State* nextState)
            : nextState(nextState)
        {

        };
        std::string getDescription() override  {
            return std::string("Current State: PURCHASED - Will be shipping soon\n");
        }
        State* getNextState() override {
            return nextState;
        };
    };

    class InTransitState : public State {
    private:
        State* nextState;
    public:
        InTransitState(State* nextState)
            : nextState(nextState)
        {

        };
        std::string getDescription() override {
            return std::string("Current State: IN_TRANSIT - Your item is on the way\n");
        }
        State* getNextState() override {
            return nextState;
        };
    };
    class DeliveredState : public State {
    private:
        State* nextState;
    public:
        DeliveredState(State* nextState)
            : nextState(nextState)
        {

        };
        std::string getDescription() override {
            return std::string("Current State: DELIVERED - Your item has arrived\n");
        }
        State* getNextState() override {
            return nextState;
        };
    };

    class Purchase {
        std::string productName;
        std::string currentState;
    public:
        Purchase(const std::string& productName)
            : productName(productName), currentState("PURCHASED") {};
        std::string getDescription() {
            std::string description = productName + " - " + currentState + "\n";

            if (currentState == "PURCHASED") {
                description += "Will be shipping soon\n";
            }
            else if (currentState == "IN_TRANSIT") {
                description += "Your item is on the way\n";
            }
            else if (currentState == "DELIVERED") {
                description += "Your item has arrived\n";
            }

            return description;
        }

        void goToNextState() {
            if (currentState == "PURCHASED") {
                currentState = "IN_TRANSIT";
            }
            else if (currentState == "IN_TRANSIT") {
                currentState = "DELIVERED";
            }
            else if (currentState == "DELIVERED") {
                std::cout << "No more states!";
            }
        };
    };
};