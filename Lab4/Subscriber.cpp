#include "stdafx.h"
#include "Subscriber.h"


Subscriber::Subscriber(string newName, string newPhone) {
	name = newName;
	phone = newPhone;
}


Subscriber::~Subscriber() {
}

string Subscriber::getName() const {
	return name;
}

string Subscriber::getPhone() const {
	return phone;
}

void Subscriber::setName(string newName) {
	name = newName;
}

void Subscriber::setPhone(string newPhone) {
	phone = newPhone;
}