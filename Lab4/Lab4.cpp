#include "stdafx.h"
#include "PhoneList.h"
#include <iostream>

int main() {
	PhoneList list = PhoneList();
	list.update(Subscriber("Gregory", "890000"));
	Subscriber subscriber = list.getCurrentItem();
	std::cout << subscriber.getName() << " " << subscriber.getPhone() << endl;
	list.nextItem();
	list.prevItem();
	list.prevItem();
	list.insert(Subscriber("VASYA", "8990"));
	list.prevItem();
	list.prevItem();
	list.insertNext(Subscriber("sdf", "8585"));
	list.insertPrev(Subscriber("sdfsdf", "8585"));
	list.nextItem(20);
	list.prevItem(20);
	list.nextItem(3);


	system("pause");
    return 0;
}



