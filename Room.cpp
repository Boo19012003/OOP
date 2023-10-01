#include <iostream>
#include <vector>
using namespace std;

class Room
{
protected:
    int ID;
    string Name;
    int Tang;
    int Sophong;
    int Succhua;
public:
    Room() { ID = 0; Name = ""; Tang = 0; Sophong = 0; Succhua = 0; }
    virtual ~Room() {}
    virtual void Nhap();
    virtual void Xuat() = 0;
    void setID(int n) { ID = n; }
    int getSucChua() { return Succhua; }
    int getTang() { return Tang; }
    string getName() { return Name; }
};
void Room::Nhap()
{
    cin >> Name;
    cin >> Tang;
    cin >> Sophong;
    cin >> Succhua;
}

class LyThuyet : public Room
{
private:
    bool maylanh;
public:
    void Nhap();
    void Xuat();
};
void LyThuyet::Nhap()
{
    Room::Nhap();
    setID(1);
    int n;
    cin >> n;
    maylanh = n == 1;
}
void LyThuyet::Xuat()
{
    cout << getName();
}

class ThucHanh : public Room
{
private:
    int soluongmaytinh;
public:
    void Nhap();
    void Xuat();
};
void ThucHanh::Nhap()
{
    Room::Nhap();
    setID(2);
    int n;
    cin >> n;
    soluongmaytinh = n;
}
void ThucHanh::Xuat()
{
    cout << getName() << endl;
}

class GiangDuong : public Room
{
private:
    int soluongmaychieu;
public:
    void Nhap();
    void Xuat();
};
void GiangDuong::Nhap()
{
    Room::Nhap();
    setID(3);
    int n;
    cin >> n;
    soluongmaychieu = n;
}
void GiangDuong::Xuat()
{
    cout << getName() << endl;
}

int main()
{
    int n, k;
    cin >> n;
    vector<Room*> qlr;
    for (int i = 0; i < n; i++)
    {
        int luachon;
        cin >> luachon;

        Room* p = nullptr;
        switch (luachon)
        {
        case 1:
            p = new LyThuyet;
            break;
        case 2:
            p = new ThucHanh;
            break;
        case 3:
            p = new GiangDuong;
            break;
        }
        p->Nhap();
        qlr.push_back(p);
    }

    int tongsucchua = 0;
    for (int i = 0; i < n; i++)
    {
        tongsucchua += qlr[i]->getSucChua();
    }
    cin >> k;
    cout << tongsucchua << endl;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (qlr[i]->getSucChua() >= k)
            a.push_back(i);
    }
    if (!a.empty())
    {
        int minIndex = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (qlr[a[i]]->getTang() < qlr[minIndex]->getTang())
                minIndex = a[i];
        }
        qlr[minIndex]->Xuat();
    }
    if (a.size()== 0)
    {
        cout << "NULL";
    }
    for (Room* room : qlr)
        delete room;

    return 0;
}

