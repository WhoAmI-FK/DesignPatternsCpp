#include "ObserverPattern.h"

using namespace observers;
int main(){
	ChatUser* user1 = new ChatUser("Jim");
	ChatUser* user2 = new ChatUser("Barb");
	ChatUser* user3 = new ChatUser("Hannah");
	ChatGroup* group1 = new ChatGroup("Gardening group");
	ChatGroup* group2 = new ChatGroup("Dog-lovers groups");

	group1->subscribe(user1);
	group1->subscribe(user2);
	group2->subscribe(user2);
	group2->subscribe(user3);

	group1->publish("Special sale on gardening supplies");
	group2->publish("It's national dog day everyone!");
	delete user1;
	delete user2;
	delete user3;
	delete group1;
	delete group2;
	return 0;
}