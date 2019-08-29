#include <iostream>
using namespace std;

struct Account {
	int id;
	int balance;
	char name[20];

	void deposit(int money) {
		balance += money;
	}
	void withdraw(int money) {
		balance -= money;
	}
	void print() {
		cout << "id:" << id << ", name:" << name << ", balance:" << balance << endl;
	}
};


int main(void)
{
	struct Account kim = {1, 1000, "kim"};
	Account lee = {1, 1000, "lee"};

	kim.deposit(1000);
	kim.print();
	kim.withdraw(1000);
	kim.print();

	lee.deposit(500);
	lee.print();
	lee.withdraw(500);
	lee.print();

	return 0;
}

