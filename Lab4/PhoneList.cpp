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
	current = --phoneBook.end();
}

Subscriber PhoneList::getCurrentItem() {
	return *current;
}

void PhoneList::update(Subscriber subscriber) {
	(*current) = subscriber;
}

void PhoneList::nextItem() {
	if (current != --phoneBook.end()) {
		*(current++);
		std::cout << "Move to next item:" << endl;
	} else {
		std::cout << "ERROR: Current value is the last element in the list" << endl;
	}
	printCurrent();
}

void PhoneList::prevItem() {
	if (current != phoneBook.begin()) {
		*(current--);
		std::cout << "Move to previous item:" << endl;
	} else {
		std:cout << "ERROR: Current value is the first element in the list" << endl;
	}
	printCurrent();
}

void PhoneList::nextItem(int n) {
	for (int i = 0; i < n; i++) {
		if (current == --phoneBook.end()) {
			cout << "WARNING: " << n << " value is stayed out of this list bound." << endl;
			break;
		}
		current++;
	}
	printCurrent();
}

void PhoneList::prevItem(int n) {
	for (int i = 0; i < n; i++) {
		if (current == phoneBook.begin()) {
			cout << "WARNING: " << n << " value is stayed out of this list bound." << endl;
			break;
		}
		current--;
	}
	printCurrent();
}

void PhoneList::printCurrent() {
	std::cout << " >     Current item is " << (*current).getName() << " " << (*current).getPhone() << endl;
}

void PhoneList::insertNext(Subscriber subscriber) {
	*(current++);
	update(subscriber);
	printCurrent();
}

void PhoneList::insertPrev(Subscriber subscriber) {
	if (current == phoneBook.begin()) {
		std::cout << "You can't add element before first record" << endl;
		return;
	} else {
		*(current--);
		update(subscriber);
		printCurrent();
	}
}

void PhoneList::insert(Subscriber subscriber) {
	phoneBook.insert(phoneBook.end(), subscriber);
	current = --phoneBook.end();
	cout << "The record have been added" << endl;
	printCurrent();
}

