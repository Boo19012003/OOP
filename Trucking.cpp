#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

vector<string> pt;
struct Thoigian
{
	int ngay, thang, nam;
};
class ChuyenHang
{
protected:
	int ma_chuyen_hang;
	Thoigian thoi_gian_xe_chay;
public:
	ChuyenHang() {
		ma_chuyen_hang = 0; thoi_gian_xe_chay.ngay = 0;
	thoi_gian_xe_chay.thang = 0; thoi_gian_xe_chay.nam = 0;
	}
	virtual void Nhap();
};

void ChuyenHang::Nhap()
{
	cout << "Ma chuyen hang: ";
	cin >> ma_chuyen_hang;
	cout << "Thoi gian xe chay (ngay_thang_nam): ";
	cin >> thoi_gian_xe_chay.ngay >> thoi_gian_xe_chay.thang >> thoi_gian_xe_chay.nam;
}
class PhuongTien : ChuyenHang
{
protected:
	string ma_phuong_tien;
	string loai_xe;
	int trong_tai;
	string xuat_xu;
	int thoi_gian_san_xuat;
	double nhien_lieu_tieu_hao;
	double doanh_thu;
public:
	PhuongTien() {
		ma_phuong_tien = ""; loai_xe = ""; trong_tai = 0; xuat_xu = "";
		thoi_gian_san_xuat = 0; nhien_lieu_tieu_hao = 0;
	}
	void Nhap();
	virtual double TienCuoc() = 0;
	string KiemTra();
	double NhienLieu();
};

void PhuongTien::Nhap()
{
	cin.ignore();
	cout << "Ma phuong tien: ";
	getline(cin,ma_phuong_tien);
	pt.push_back(ma_phuong_tien);
	cout << "Xuat xu: ";
	getline(cin, xuat_xu);
	cout << "Thoi gian san xuat: ";
	cin >> thoi_gian_san_xuat;
}

string PhuongTien::KiemTra()
{
	return ma_phuong_tien;
}

double PhuongTien::NhienLieu()
{
	return nhien_lieu_tieu_hao;
}
class CongTenNo : public PhuongTien
{
private:
	int Khoi_luong_hang;
public:
	CongTenNo() { Khoi_luong_hang = 0; PhuongTien::loai_xe = "Cong ten no";
	PhuongTien::trong_tai = 35; PhuongTien::nhien_lieu_tieu_hao = 40 / 100;
	}
	void Nhap();
	double TienCuoc();
};

void CongTenNo::Nhap()
{
	PhuongTien::Nhap();
	do
	{
		cout << "Khoi luong hang ( <= 35 tan): ";
		cin >> Khoi_luong_hang;
	} while (!(Khoi_luong_hang > 0 && Khoi_luong_hang <= 35));
}

double CongTenNo::TienCuoc()
{
	return Khoi_luong_hang * 100 * 150;
}

class XeBen : public PhuongTien
{
private:
	int luong_hang;
public:
	XeBen() {
		luong_hang = 0; PhuongTien::loai_xe = "Xe Ben";
		PhuongTien::trong_tai = 20; PhuongTien::nhien_lieu_tieu_hao = 40 / 100;
	}
	void Nhap();
	double TienCuoc();
};

void XeBen::Nhap()
{
	PhuongTien::Nhap();
	do
	{
		cout << "Khoi luong hang ( <= 20 met khoi): ";
		cin >> luong_hang;
	} while (!(luong_hang > 0 && luong_hang <= 20));
}

double XeBen::TienCuoc()
{
	return luong_hang * 5000;
}

class XeDongLanh : public PhuongTien
{
private:
	int Khoi_luong_hang;
public:
	XeDongLanh() { Khoi_luong_hang = 0; PhuongTien::loai_xe = "Xe Dong Lanh";
	PhuongTien::trong_tai = 3.5; PhuongTien::nhien_lieu_tieu_hao = 25 / 100;
	}
	void Nhap();
	double TienCuoc();
};

void XeDongLanh::Nhap()
{
	PhuongTien::Nhap();
	do
	{
		cout << "Khoi luong hang ( <= 3,5 tan): ";
		cin >> Khoi_luong_hang;
	} while (!(Khoi_luong_hang > 0 && Khoi_luong_hang <= 3.5));
}

double XeDongLanh::TienCuoc()
{
	return Khoi_luong_hang * 100 * 200;
}

class TuyenDuong : public ChuyenHang
{
protected:
	int ma_tuyen_duong;
	string ten_tuyen_duong;
	int so_km;
public:
	TuyenDuong() { ma_tuyen_duong = 0; ten_tuyen_duong = ""; so_km = 0; }
	void Nhap();
	double SoKm();
	int MaChuyenHang();
};

void TuyenDuong::Nhap()
{
	cout << "Ma tuyen duong: ";
	cin >> ma_tuyen_duong;
	cin.ignore();
	cout << "Ten tuyen duong: ";
	getline(cin, ten_tuyen_duong);
	cout << "So km: ";
	cin >> so_km;
	ChuyenHang::Nhap();
}

double TuyenDuong::SoKm()
{
	return so_km;
}

int TuyenDuong::MaChuyenHang()
{
	return ma_chuyen_hang;
}

class QuanLyXe
{
private:
	vector<PhuongTien*> qlpt;
	vector<TuyenDuong*> qltd;
public:
	void Menu();
};

void QuanLyXe::Menu()
{
	int n;
	PhuongTien* p{};
	TuyenDuong* t;
	
	do
	{
		system("cls");
		cout << "======================== MENU ========================" << endl;
		cout << "1.Xe cong" << endl;
		cout << "2.Xe Ben" << endl;
		cout << "3.Xe dong lanh" << endl;
		cout << "4.Tien cuoc tung xe" << endl;
		cout << "5.Doanh thu thung xe trong thang" << endl;
		cout << "0.Ket thuc" << endl;
		cout << "======================== MENU ========================" << endl;

		do
		{
			cout << "Nhap lua chon: ";
			cin >> n;
		} while (!(n > -1 && n < 6));

		switch (n)
		{
		case 1:
		{
			p = new CongTenNo;
			break;
		}
		case 2:
		{
			p = new XeBen;
			break;
		}
		case 3:
		{
			p = new XeDongLanh;
			break;
		}
		case 4:
		{
			double temp;
			cout << "Tien cuoc cua cac chuyen hang la" << endl;
			for (int i = 0; i < qlpt.size(); i++)
			{
				temp = qlpt[i]->TienCuoc()* qltd[i]->SoKm();
				cout << qltd[i]->MaChuyenHang() << ": " << temp / 1000 << "000 dong" << endl;
			}
			system("pause");
			break;
		}
		case 5:
		{
			map<string, double> dt;
			for (int i = 0; i < qlpt.size(); i++)
			{
				for (int j = 0; j < qlpt.size(); j++)
				{
					if (qlpt[i]->KiemTra() == qlpt[j]->KiemTra())
					{
						dt[qlpt[j]->KiemTra()] += qlpt[j]->TienCuoc() * qltd[j]->SoKm();
					}
				}
			}
			for (auto x : dt)
			{
				cout << x.first << ": " << x.second / 1000 << "000 dong" << endl;
			}
			system("pause");
			break;
		}
		case 0:
			for (auto i : qlpt)
				delete i;
			for (auto i : qltd)
				delete i;
			return;
		}
		if (n == 1 || n ==2 || n == 3)
		{
			p->Nhap();
			qlpt.push_back(p);
			t = new TuyenDuong;
			t->Nhap();
			qltd.push_back(t);
		}
	} while (n);
}

int main()
{
	QuanLyXe q;
	q.Menu();
	return 0;
}