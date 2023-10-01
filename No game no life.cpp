#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
protected:
	int type;
	string name;
	double price;
	string producer;
public:
	virtual void Input();
	double get_price() { return price; }
	void set_type(int n) { type = n; }
	int get_type() { return type; }
};
void Item::Input()
{
	cout << "Name: ";
	cin >> name;
	cout << "Price: ";
	cin >> price;
	cout << "Producer: ";
	cin >> producer;
}

class Quan : public Item
{
private:
	double length;
public:
	void Input();
};
void Quan::Input()
{
	Item::Input();
	cout << "Length: ";
	cin >> length;
}

class Ao : public Item
{
private:
	string color;
	bool co_ao;
public:
	void Input();
};
void Ao::Input()
{
	Item::Input();
	cout << "Color: ";
	cin >> color;
	int n;
	cout << "Co ao: ";
	do
	{
		cin >> n;
	} while (n == 1 || n == 0);
	co_ao = n;
}

class Mu : public Item
{
private:
	double level;
public:
	void Input();
};
void Mu::Input()
{
	Item::Input();
	cout << "Level: ";
	cin >> level;
}

class List_Item
{
private:
	vector<Item*> listi;
public:
	void list();
};

void List_Item::list()
{
	int n;
	Item* t{};

	do
	{
		system("cls");
		cout << "======================== MENU ========================" << endl;
		cout << "1.Quan jean" << endl;
		cout << "2.Quan kaki" << endl;
		cout << "3.Ao ngan tay" << endl;
		cout << "4.Ao dai tay" << endl;
		cout << "5.Mu sat" << endl;
		cout << "6.Mu bac" << endl;
		cout << "7.Mu vang" << endl;
		cout << "8.Tong gia tri item" << endl;
		cout << "0.Ket thuc" << endl;
		cout << "======================== MENU ========================" << endl;

		do
		{
			cout << "Nhap lua chon: ";
			cin >> n;
		} while (!(n > -1 && n <= 8));

		switch (n)
		{
		case 1:
		case 2:
		{
			t = new Quan();
			break;
		}
		case 3:
		case 4:
		{
			t = new Ao();
			break;
		}
		case 5:
		case 6:
		case 7:
		{
			t = new Mu();
			break;
		}
		case 8:
		{
			double True_price(0);
			double buff(0);
			for (auto i : listi)
			{

				if (buff < 1.5 && i->get_type() == 6)
					buff = 1.5;
				else if (buff < 3 && i->get_type() == 7)
					buff = 3;
			}
			for (auto i : listi)
			{
				switch (i->get_type())
				{
				case 1:
				{
					True_price += i->get_price() * 0.8 * buff;
					break;
				}
				case 2:
				{
					True_price += i->get_price() * 1.5 * buff;
					break;
				}
				case 3:
				case 4:
				{
					True_price += i->get_price() * buff;
					break;
				}
				case 5:
				{
					True_price += 0;
				}
				case 6:
				case 7:
				{
					True_price += i->get_price();
					break;
				}
				}
			}
			cout << "Tong gia tri vat pham: " << True_price;
		}
		case 0:
			for (auto i : listi)
				delete i;
			return;
		}
		if (n >= 1 && n <= 7)
		{
			t->Input();
			t->set_type(n);
			listi.push_back(t);
		}
	} while (n);
}
int main()
{
	List_Item l;
	l.list();
	return 0;
}