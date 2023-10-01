#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persion
{
private:
	int type;
	string name;
	int age;
public:
	virtual void input();
	void setType(int n) { type = n; }
	int getType() { return type; }
};
void Persion::input()
{
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
}

class BestFriend : public Persion
{
private:
	int phone;
public:
	void input();
};
void BestFriend::input()
{
	Persion::input();
	cout << "Phone: "; cin >> phone;
}

class BoyFriend : public Persion
{
private:
	int income;
public:
	void input();
};
void BoyFriend::input()
{
	Persion::input();
	cout << "Income: "; cin >> income;
}
int main()
{
	return 0;
}