#include "stdafx.h"
#include <iterator>
#include <iostream>
#include "PhoneList.h"


PhoneList::PhoneList() {
	fillBook();
	printPhoneBook();
}


PhoneList::~PhoneList() {
}

std::string PhoneList::getRandomName() {
	int index = rand() % 10 + 1;
	std::string name;
	switch (index) {
	case 1:
		name = "Anna";
		break;
	case 2:
		name = "Andry";
		break;
	case 3:
		name = "Bob";
		break;
	case 4:
		name = "Bill";
		break;
	case 5:
		name = "Gregory";
		break;
	case 6:
		name = "Chloy";
		break;
	case 7:
		name = "Richard";
		break;
	case 8:
		name = "Henry";
		break;
	case 9:
		name = "Marry";
		break;
	case 10:
		name = "Frank";
		break;
	default:
		name = "Unnamed";
		break;
	}
	return name;
}

std::string PhoneList::getRandomNumber() {
	return std::to_string(rand() % 900000 + 999);
}

void PhoneList::fillBook() {
	for (int i = 0; i < 10; i++) {
		phoneBook.push_back(Subscriber(getRandomName(), getRandomNumber()));
	}
	setLastItemAsCurrent();
}

void PhoneList::printPhoneBook() {
	for (const auto& subscriber : phoneBook) {
		std::cout << subscriber.getName() << " " << subscriber.getPhone() << endl;
		std::cout << "\n";
	}
}

void PhoneList::setLastItemAsCurrent() {
	current = &phoneBook.back();
}

Subscriber PhoneList::getCurrentItem() {
	return *current;
}

void PhoneList::update(Subscriber subscriber) {
	(*current).setName(subscriber.getName());
	(*current).setPhone(subscriber.getPhone());
}


