#include <string>

using namespace std;

class Subscriber {
private:
	string name;
	string phone;

public:
	Subscriber(string newName, string newPhone);
	~Subscriber();

	string getName() const;
	string getPhone() const;
	void setName(string newName);
	void setPhone(string newPhone);
};

