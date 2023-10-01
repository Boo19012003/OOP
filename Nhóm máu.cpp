#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Nguoi
{
protected:
	string ten;
	string nhom_mau;
	string loai;
	map<string,string> cho;
	map<string,string> nhan;
public:
	Nguoi() { ten = ""; nhom_mau = ""; loai = "";}
	void Nhap();
	void Xuat();
	bool Ditruyen(string bo, string me, string con);
	void TruyenMau();
	bool Kiemtranhommau(string mau, string rh);
	string Ten();
	string NhomMau();
	string Loai();
};

void Nguoi::Nhap()
{
	int n, m;
	cout << "Nhap Ten: "; cin >> ten;
	do
	{
		system("cls");
		cout << "===== Nhom mau =====" << endl;
		cout << "1.Mau O" << endl;
		cout << "2.Mau A" << endl;
		cout << "3.Mau B" << endl;
		cout << "4.Mau AB" << endl;
		cout << "====== =========" << endl;
		cout << "Nhap lua chon: "; cin >> n;
	} while (!(n > 0 && n < 5));

	do
	{
		system("cls");
		cout << "===== Loai =====" << endl;
		cout << "1.RH+" << endl;
		cout << "2.RH-" << endl;
		cout << "===== Nhom mau =====" << endl;
		cout << "Nhap lua chon: "; cin >> m;
	} while (!(m > 0 && m < 3));

	switch (n)
	{
	case 1:
		nhom_mau = "O";
		break;
	case 2:
		nhom_mau = "A";
		break;
	case 3:
		nhom_mau = "B";
		break;
	case 4:
		nhom_mau = "AB";
		break;
	}

	switch (m)
	{
	case 1:
		loai = "+";
		break;
	case 2:
		loai = "-";
		break;
	}
	TruyenMau();
}

void Nguoi::Xuat()
{
	cout << ten << " " << nhom_mau << loai << endl;
	cout << "Co the cho mau: ";
	for (auto x : cho)
	{
		cout << x.first;
		if (x.second == "+")
			cout << "+ ";
		else if (x.second == "-")
			cout << "- ";
		else
		{
			cout << "+ ";
			cout << x.first << "- ";
		}
	}
	cout << endl;

	cout << "Co the nhan mau: ";
	for (auto x : nhan)
	{
		cout << x.first;
		if (x.second == "+")
			cout << "+ ";
		else if (x.second == "-")
			cout << "- ";
		else
		{
			cout << "+ ";
			cout << x.first << "- ";
		}
	}
	cout << endl;
}

bool Nguoi::Ditruyen(string bo, string me, string con)
{
	if ((bo == "A" && me == "A" || me == "O") || (me == "A" && bo == "A" || bo == "O") 
		&& (con == "A" || con == "O"))
		return true;

	else if ((bo == "A" && me == "B") || (me == "A" && bo == "B") 
		&& (con == "A" || con == "O" || con == "B" || con == "AB"))
		return true;

	else if ((bo == "A" || bo == "B" || bo == "AB" && me == "AB") || (me == "A" || me == "B" || me == "AB" && bo == "AB")
		&& (con == "A" || con == "B" || con == "AB"))
		return true;

	else if ((bo == "B" && me == "B" || me == "O") || (me == "B" && bo == "B" || bo == "O") 
		&& (con == "B" || con == "O"))
		return true;

	else if ((bo == "O" && me == "AB") || (me == "O" && bo == "AB") 
		&& (con == "A" || con == "B"))
		return true;

	return false;
}

void Nguoi::TruyenMau()
{
	if (nhom_mau == "O")
	{
		cho["O"] = (loai == "+") ? "+" : "+-";
		cho["A"] = (loai == "+") ? "+" : "+-";
		cho["B"] = (loai == "+") ? "+" : "+-";
		cho["AB"] = (loai == "+") ? "+" : "+-";

		nhan["O"] = (loai == "+") ? "+-" : "+";
	}
	else if (nhom_mau == "A")
	{
		cho["A"] = (loai == "+") ? "+" : "+-";
		cho["Ab"] = (loai == "+") ? "+" : "+-";

		nhan["O"] = (loai == "+") ? "+-" : "-";
		nhan["A"] = (loai == "+") ? "+-" : "-";
	}
	else if (nhom_mau == "B")
	{
		cho["B"] = (loai == "+") ? "+" : "+-";
		cho["AB"] = (loai == "+") ? "+" : "+-";

		nhan["O"] = (loai == "+") ? "+" : "-";
		nhan["B"] = (loai == "+") ? "+" : "-";
	}
	else if (nhom_mau == "AB")
	{
		cho["AB"] = (loai == "+") ? "+" : "+-";

		nhan["O"] = (loai == "+") ? "+-" : "-";
		nhan["A"] = (loai == "+") ? "+-" : "-";
		nhan["B"] = (loai == "+") ? "+-" : "-";
		nhan["AB"] = (loai == "+") ? "+-" : "-";
	}
}

string Nguoi::Ten()
{
	return ten;
}

string Nguoi::NhomMau()
{
	return nhom_mau;
}
string Nguoi::Loai()
{
	return loai;
}
bool Nguoi::Kiemtranhommau(string mau, string rh)
{
	for (auto x : nhan)
		if (x.first == mau && x.second == rh)
			return true;
	return false;
}
class QuanLyNguoi
{
private:
	vector<Nguoi*> dsn;
public:
	void Menu();
};

void QuanLyNguoi::Menu()
{
	int n;
	Nguoi* p;

	do
	{
		system("cls");
		cout << "======================== MENU ========================" << endl;
		cout << "1.Them nguoi" << endl;
		cout << "2.Kiem tra huyet thong" << endl; 
		cout << "3.Danh sach nguoi co the chuyen mau." << endl;
		cout << "4.Xuat danh sach" << endl;
		cout << "0.Ket thuc" << endl;
		cout << "======================== MENU ========================" << endl;
		cout << "nhap lua chon: "; cin >> n;

		switch (n)
		{
		case 1:
		{
			p = new Nguoi;
			p->Nhap();
			dsn.push_back(p);
			break;
		}
		case 2:
		{
			string nhan;
			cin >> nhan;
			for (int i = 0; i < dsn.size(); i++)
			{
				if (dsn[i]->Ten() != nhan &&
					dsn[i]->Kiemtranhommau(dsn[i]->NhomMau(), dsn[i]->Loai()) == true)
					dsn[i]->Ten();
			}
		}
		case 3:
		{
			string bo, me, con;
			cin >> bo >> me >> con;
			if (dsn[1]->Ditruyen(bo, me, con) == true)
				cout << "Phu hop voi quy luat di truyen";
			else 
				cout << "Khongo phu hop voi quy luat di truyen";
		}
		case 4:
		{
			for (int i = 0; i < dsn.size(); i++)
				dsn[i]->Xuat();
		}
		case 0:
			return;
		}
	} while (n);

}
int main()
{
	QuanLyNguoi a;
	a.Menu();

	return 0;
}