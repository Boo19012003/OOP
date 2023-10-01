#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Tuong
{
protected:
	string ten;
	int gia_tri;
	int tan_cong;
	int phong_thu;
	string chieu_thuc;
	string he;
	string toc;
public:
	Tuong() {
		ten = ""; gia_tri = 0; tan_cong = 0; phong_thu = 0; chieu_thuc = "";
		he = ""; toc = "";
	}
	virtual void Nhap();
	void Xuat();
	string Ten();
	void TangChiSo(const vector<Tuong*>& qlt, int n, int i);
	int TongSatThuong(int m);
};

void Tuong::Nhap()
{
	cout << "Sat thuong: "; cin >> tan_cong;
	cout << "Phong thu: "; cin >> phong_thu;
}

void Tuong::Xuat()
{
	cout << "Ten: " << ten << endl;
	cout << "Gia tien: " << gia_tri << endl;
	cout << "Tan cong: " << tan_cong << endl;
	cout << "Phong thu: " << phong_thu << endl;
	cout << "Chieu thuc: " << chieu_thuc << endl;
	if (he != "")
		cout << "he: " << he << endl;
	cout << "Toc: " << toc << endl;
}

string Tuong::Ten()
{
	return ten;
}

void Tuong::TangChiSo(const vector<Tuong*>& qlt, int n, int i)
{
	if (n >= 2)
	{
		if (qlt[i]->toc == "Cong nghe")
		{
			if (qlt[i]->ten == "Jarvan" || qlt[i]->ten == "Sivir")
			{
				qlt[i]->tan_cong += 15;
				qlt[i]->phong_thu += 15;
			}
		}
		else if (qlt[i]->toc == "Tien cong")
		{
			if (qlt[i]->ten == "Reksai" || qlt[i]->ten == "Illaoi")
			{
				qlt[i]->tan_cong += 30;
			}
		}
		else if (qlt[i]->he == "Dau si")
		{
			if (n == 2)
			{
				if (qlt[i]->ten == "Jarvan" || qlt[i]->ten == "Reksai" || qlt[i]->ten == "Illaoi")
					qlt[i]->phong_thu += 15;
			}
			else
			{
				if (qlt[i]->ten == "Jarvan" || qlt[i]->ten == "Reksai" || qlt[i]->ten == "Illaoi")
					qlt[i]->phong_thu += 30;
			}
		}
	}
}

int Tuong::TongSatThuong(int m)
{
	if (ten == "Jarvan")
		return phong_thu * 2 * 4;
	else if (ten == "Reksai")
	{
		int temp = m / 4;
		return tan_cong * m + tan_cong * temp;
	}
	else if (ten == "Sivir")
		return tan_cong * 2 * m;
	else if (ten == "Illaoi")
		return ((tan_cong + phong_thu) / 2) * m;
}
class Javan : public Tuong
{
public:
	Javan() { ten = "Jarvan"; gia_tri = 1; chieu_thuc = "Thuong Thuat"; he = "Dau si"; toc = "Cong nghe"; }
	void Nhap();
};

void Javan::Nhap()
{
	Tuong::Nhap();
}

class Reksai : public Tuong
{
public:
	Reksai() { ten = "Reksai"; gia_tri = 2; chieu_thuc = "Nu hoang phan no"; he = "Dau si"; toc = "Tien toc"; }
	void Nhap();
};

void Reksai::Nhap()
{
	Tuong::Nhap();
}

class Sivir : public Tuong
{
public:
	Sivir() { ten = "Sivir"; gia_tri = 4; chieu_thuc = "Guom Boomerang"; toc = "Cong nghe"; }
	void Nhap();
};

void Sivir::Nhap()
{
	Tuong::Nhap();
}

class Illaoi : public Tuong
{
public:
	Illaoi() { ten = "Illaoi"; gia_tri = 1; chieu_thuc = "Loi ran khac nghiet"; he = "Dau si"; toc = "Tien toc"; }
	void Nhap();
};

void Illaoi::Nhap()
{
	Tuong::Nhap();
}

class QuanlyTuong
{
private:
	vector<Tuong*> qlt;
public:
	void Menu();
};

void QuanlyTuong::Menu()
{
	int n, m, tong_gia_tri(0);
	Tuong* t{};

	do
	{
		system("cls");
		cout << "======================== MENU ========================" << endl;
		cout << "1.Jarvan " << endl;
		cout << "2.Reksai " << endl;
		cout << "3.Sivir " << endl;
		cout << "4.Illaoi  " << endl;
		cout << "5.Xuat ra cac tuong" << endl;
		cout << "6.Tong sat thuong cua cac tuong" << endl;
		cout << "0.Ket thuc" << endl;
		cout << "======================== MENU ========================" << endl;

		do
		{
			cout << "Nhap lua chon: ";
			cin >> n;
		} while (!(n >= 0 && n <= 6 ));

		switch (n)
		{
		case 1:
		{
			tong_gia_tri += 1;
			t = new Javan;
			break;
		}
		case 2:
		{
			tong_gia_tri += 2;
			t = new Reksai;
			break;
		}
		case 3:
		{
			tong_gia_tri += 4;
			t = new Sivir;
			break;
		}
		case 4:
		{
			tong_gia_tri += 1;
			t = new Illaoi;
			break;
		}
		case 5:
		{
			for (int i = 0; i < qlt.size(); i++)
			{
				qlt[i]->Xuat();
				cout << endl;
			}
			system("pause");
			break;
		}
		case 6:
		{
			map<string, int> mp;
			map<string, int> mpp;
			cout << "So luot giao tranh: "; cin >> m;
			for (int i = 0; i < qlt.size(); i++)
				mp[qlt[i]->Ten()]++;

			for (auto x : mp)
			{
				if (x.second > 0)
				{
					if (x.first == "Jarvan" || x.first == "Sivir")
						mpp["Cong nghe"]++;
					else if (x.first == "Reksai" || x.first == "Illaoi")
						mpp["Tien cong"]++;
					else if (x.first == "Jarvan " || x.first == "Reksai" || x.first == "Illaoi ")
						mpp["Dau si"]++;
				}
			}
			for (auto x : mpp)
			{
				for (int i = 0; i < qlt.size(); i++)
				{
					qlt[i]->TangChiSo(qlt, x.second, i);
				}
			}
			for (int i = 0; i < qlt.size(); i++)
			{
				cout << qlt[i]->Ten() << " - sat thuong gay ra: " << qlt[i]->TongSatThuong(m) << endl;
			}
			cout << "Tong gia tri: " << tong_gia_tri << endl;
			system("pause");
			break;
		}
		case 0:
			return;
		}
		if (n >= 1 && n <= 4)
		{
			t->Nhap();
			qlt.push_back(t);
		}
	} while (n);

}
int main()
{
	QuanlyTuong t;
	t.Menu();
	return 0;
}