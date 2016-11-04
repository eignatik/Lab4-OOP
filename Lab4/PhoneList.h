#include <string> 
#include <list>
#include "Subscriber.h"

class PhoneList {
private:
	typedef std::list<Subscriber> PhoneBook;
	PhoneBook phoneBook;
	Subscriber* current;

	std::string getRandomName();
	std::string getRandomNumber();
	void fillBook();
	void setLastItemAsCurrent();

public:
	PhoneList();
	~PhoneList();
	void printPhoneBook();
	Subscriber getCurrentItem();
	void nextItem();
	void nextItem(int n);
	void prevItem();
	void prevItem(int n);
	void insertNext(Subscriber subscriber);
	void insertPrev(Subscriber subscriber);
	void update(Subscriber subscriber);
	void insert(Subscriber subscriber);

	//TODO Develop: look curent record, go to next, previos, insert before\after curent, update current, insert to the end, go to through n recors
};

