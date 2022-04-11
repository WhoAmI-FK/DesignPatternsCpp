#include "StatePattern.h"

using namespace state;

int main()
{
	DeliveredState* deliveredState = new DeliveredState(nullptr);
	InTransitState* inTransitState = new InTransitState(deliveredState);
	PurchasedState* purchasedState = new PurchasedState(inTransitState);
	
	Purchase* purchase = new Purchase("Shoes", purchasedState);

	std::cout << purchase->getDescription() << "\n";

	purchase->goToNextState();
	std::cout << purchase->getDescription() << "\n";
	
	purchase->goToNextState();
	std::cout << purchase->getDescription() << "\n";


	delete deliveredState;
	delete inTransitState;
	delete purchasedState;
	delete purchase;
	return 0;
}