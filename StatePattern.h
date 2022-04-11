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
        PurchasedState(State* nextState=nullptr)
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
        InTransitState(State* nextState=nullptr)
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
        DeliveredState(State* nextState=nullptr)
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
        State* currentState;
    public:
        Purchase(const std::string& productName,
            State* initialState)
            : productName(productName), currentState(initialState) {};
        std::string getDescription() {
            return currentState->getDescription();
        }

        void goToNextState() {
            if(currentState->getNextState())
            currentState = currentState->getNextState();
            else std::cout << "No more states!\n";
        };
    };
};