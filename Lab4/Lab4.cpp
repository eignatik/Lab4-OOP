#include "stdafx.h"
#include "PhoneList.h"
#include <iostream>

int main() {
	PhoneList list = PhoneList();
	list.update(Subscriber("Gregory", "890000"));
	Subscriber subscriber = list.getCurrentItem();
	std::cout << subscriber.getName() << " " << subscriber.getPhone() << endl;
	system("pause");
    return 0;
}



