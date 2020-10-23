#include<iostream>
using namespace std;
#include<string>
#include<fstream>

// khai báo c?u trúc ngày tháng nam sinh
struct date
{
	int ngay;
	int thang;
	int nam;
};
typedef struct date DATE;

// hàm d?c d? li?u ngày tháng nam t? file
void Doc_Ngay_Thang_Nam(ifstream &filein, DATE &date)
{
	filein >> date.ngay;
	filein.seekg(1, 1); // d?ch sang ph?i 1 byte d? b? qua kí t? '/'
	filein >> date.thang;
	filein.seekg(1, 1); // d?ch sang ph?i 1 byte d? b? qua kí t? '/'
	filein >> date.nam;
}

// khai báo c?u trúc sinh viên
struct sinhvien
{
	string hoten;
	string masv;
	DATE ngaysinh;
	float dtb;
};
typedef struct sinhvien SINHVIEN;

// khai báo c?u trúc 1 cái node sinh viên
struct node
{
	SINHVIEN data; // d? li?u c?a node
	struct node *pNext; // con tr? dùng d? liên k?t gi?a các cái node v?i nhau
};
typedef struct node NODE;

// ========== KHAI BÁO C?U TRÚC DANH SÁCH LIÊN K?T ÐON CÁC SINH VIÊN =========

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

// hàm kh?i t?o danh sách liên k?t don các sinh viên
void KhoiTaoDanhSach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm kh?i t?o 1 cái node d? chu?n b? thêm vào danh sách
NODE *KhoiTaoNode(SINHVIEN x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x; // dua d? li?u c?a bi?n sinh vien x vào data c?a cái Node p
	p->pNext = NULL; // kh?i t?o node p nhung node p chua có liên k?t d?n node nào h?t
	return p;
}

// hàm thêm 1 cái node sinh viên vào d?u danh sách
void ThemDau(LIST &l, NODE *p)
{
	// n?u danh sách r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cung chính là node d?u và node cu?i
	}
	else
	{
		p->pNext = l.pHead; // cho con tr? p tr? d?n pHead
		l.pHead = p; // c?p nh?t l?i pHead là node p
	}
}

// hàm thêm 1 cái node sinh viên vào cu?i danh sách
void ThemCuoi(LIST &l, NODE *p)
{
	// n?u danh sách r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thêm vào cung chính là node d?u và node cu?i
	}
	else
	{
		l.pTail->pNext = p; // cho con tr? c?a pTail tr? d?n node p
		l.pTail = p; // c?p nh?t l?i pTail chính là node p
	}
}

// hàm d?c d? li?u 1 sinh viên t? file
void Doc_Thong_Tin_1_Sinh_Vien(ifstream &filein, SINHVIEN &sv)
{
	// d?c h? tên sinh viên
	getline(filein, sv.hoten, ','); // d?c d?n d?u ',' thì d?ng
	filein.seekg(1, 1); // t?i v? trí hi?n t?i d?ch sang ph?i 1 byte d? b? kho?ng tr?ng ' '
	// d?c mã sinh viên
	getline(filein, sv.masv, ','); // d?c d?n d?u ',' thì d?ng
	filein.seekg(1, 1); // t?i v? trí hi?n t?i d?ch sang ph?i 1 byte d? b? kho?ng tr?ng ' '
	// d?c thông tin ngày tháng nam sinh
	Doc_Ngay_Thang_Nam(filein, sv.ngaysinh);
	filein.seekg(2, 1); // t?i v? trí hi?n t?i d?ch sang ph?i 2 byte d? b? d?u ph?y và kho?ng tr?ng ' '
	// d?c di?m trung bình
	filein >> sv.dtb;

	// t?o bi?n t?m d? d?c cái kí t? xu?ng dòng ? cu?i dòng
	string temp;
	getline(filein, temp);
}

// hàm d?c danh sách sinh viên t? file
void Doc_Danh_Sach_Sinh_Vien(ifstream &filein, LIST &l)
{
	// d?c d?n cu?i file thì d?ng
	while (!filein.eof())
	{
		// BU?C 1: Ð?C THÔNG TIN SINH VIÊN
		SINHVIEN sv;
		Doc_Thong_Tin_1_Sinh_Vien(filein, sv);
		// BU?C 2: KH?I T?O 1 CÁI NODE SINH VIÊN
		NODE *p = KhoiTaoNode(sv);
		// BU?C 3: THÊM SINH VIÊN(thêm node p) VÀO DANH SÁCH LIÊN K?T ÐON CÁC SINH VIÊN
		ThemCuoi(l, p);
	}
}

// hàm xu?t d? test d? li?u
void Xuat(SINHVIEN sv)
{
	cout << "\nHo ten:" << sv.hoten;  
	cout << "\nMa sinh vien:" << sv.masv;
	cout << "\nNgay sinh:" << sv.ngaysinh.ngay << "/" << sv.ngaysinh.thang << "/" << sv.ngaysinh.nam;
	cout << "\nDiem trung binh:" << sv.dtb;
}

// hàm xu?t danh sách sinh viên
void Xuat_Danh_Sach_Sinh_Vien(LIST l)
{
	int dem = 1;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "\n\n\t\t SINH VIEN THU " << dem++;
		Xuat(k->data);
	}
}

int main()
{
	LIST l;
	KhoiTaoDanhSach(l);
	// m? file lên
	ifstream filein;
	filein.open("SINHVIEN.TXT", ios::in);
	Doc_Danh_Sach_Sinh_Vien(filein, l);
	Xuat_Danh_Sach_Sinh_Vien(l);

	filein.close();
	system("pause");
	return 0;
}
