#include <iostream>
#include<cstring>
#include<conio.h>
using namespace std;


struct sinhvien
{
	string hoten;
	string mssv;
	int namsinh;
	string diachi;
};

struct node
{
	sinhvien data;
	struct node *pNext;
};
typedef struct node NODE; // doi node thanh NODE co the chay tren c, c++

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;


void creatLIST(LIST &l);
NODE *creatNODE(sinhvien sv);
void addHead(list &l, NODE *p);
void addTail(list &l, NODE *p);
void nhap_thong_tin_sinh_vien(sinhvien &sv);
void xuat_thong_tin_sinh_vien(sinhvien sv);
NODE *searchINFO(LIST l, string MSSV);

void nhap_danh_sach(LIST &l);
void xuat_danh_sach(LIST l);


int main()
{
	int chucnang=-1;
	LIST danhsach1;
	creatLIST(danhsach1);
	
	do
	{
		cout<<endl;
		cout<<"0. Thoat ! "<<endl;
		cout<<"1. Nhap danh sach "<<endl;
		cout<<"2. Xuat danh sach "<<endl;
		cout<<"3. Tim thong tin sinh vien "<<endl;
		cout<<"\n Chon chuc nang : ";
		cin>>chucnang;
		system("cls"); // xoa man hinh
		switch(chucnang)
		{
			case(1):
				{
					nhap_danh_sach(danhsach1); break;
				}
			case(2):
				{
					xuat_danh_sach(danhsach1); break;
				}
			case(3):
				{
					string maso;
					cout<<"Nhap mssv can tim :";
					cin.ignore();
					getline(cin,maso);
					
					NODE *k = searchINFO(danhsach1,maso);
					if(k == NULL)
					{
						cout<<"Khong tim thay sinh vien co ma so "<<maso<<" ! "<<endl;
						break;
					}
					sinhvien a = k->data;
					xuat_thong_tin_sinh_vien(a);
					break;
				}
			default:
				{
					cout<<"Chuc nang khong hop le ! ";
					break;
				}
		}
	}
	while(chucnang!=0);
	system("pauses");
	return 0;
}


void creatLIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *creatNODE(sinhvien sv)
{
	NODE *p = new NODE;
	p->data = sv;
	p->pNext = NULL;	
}

void nhap_thong_tin_sinh_vien(sinhvien &sv)
{
	cout<<"Nhap ten sinh vien : ";
	getline(cin,sv.hoten);
	
	cout<<"Nhap MSSV : ";
	fflush(stdin);
	getline(cin,sv.mssv);
	
	cout<<"Nhap nam sinh : ";
	cin>>sv.namsinh;
	
	fflush(stdin);
	cout<<"Nhap dia chi : ";
	getline(cin,sv.diachi);
}

void xuat_thong_tin_sinh_vien(sinhvien sv)
{
	cout<<sv.hoten<<"\t"<<sv.namsinh<<"\t"<<sv.mssv<<"\t"<<sv.diachi;
}

void nhap_danh_sach(LIST &l)
{
	int kt=0;
	do
	{
		system("cls");
		
		cout<<"1. Tiep tuc nhap thong tin vao danh sach "<<endl;
		cout<<"2. Huy nhap thong tin vao danh sach "<<endl;
		cin>>kt;
		system("cls");
		cin.ignore();
		switch(kt)
		{
			case(1):
				{
					cout<<"=============================Nhap data cho NODE sv============================  \n";
					// tao 1 sinh vien & nhap thong tin cho sinh vien 
					sinhvien a;
					nhap_thong_tin_sinh_vien(a);
		
					NODE *p = creatNODE(a); // them sinhvien a vao NODE p
					addTail(l,p);           // them NODE p vao danh sach
					cout<<"Da them thanh cong ! "<<endl;
					break;
				}
		}	
	}
	while( kt!= 2);
	
}

void xuat_danh_sach(LIST l)
{
	if(l.pHead == NULL) // neu danh sach chua co gi
	{
		cout<<"Danh sach rong !"<<endl;
	}
	else
	{
		for(NODE *i = l.pHead; i != NULL; i = i->pNext)
		{
			xuat_thong_tin_sinh_vien(i->data);
			cout<<endl;
		}
	}
}
void addHead(list &l, NODE *p)
{
	if(l.pHead == NULL) 			// neu NODE dau tien bang  NULL, co nghia la LIST chua co NODE nao het
	{
		l.pHead = l.pTail = p; 	// thi NODE dau cung la NODE cuoi va bang p ( NODE dau = NODE cuoi = p )
	}
	else                        // nguoc lai, neu lIST da co NODE
	{
		p->pNext = l.pHead;			// do chen vao dau LIST, nen con tro pNext cua p se tro vao NODE dau tien
		l.pHead = p;							// cap nhat lai NODE dau tien chinh la p
	}
}

void addTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL) 			// neu NODE dau tien bang  NULL, co nghia la LIST chua co NODE nao het
	{
		l.pHead = l.pTail = p; 	// thi NODE cuoi cung la NODE cuoi va bang p ( NODE dau = NODE cuoi = p )
	}
	else						// nguoc lai, neu lIST da co NODE
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

NODE *searchINFO(LIST l, string MSSV)
{
	for(NODE *i = l.pHead; i->pNext != NULL; i = i->pNext)
	{
		
		if(i->data.mssv == MSSV)
		{
			return i;
		}
	}
	return NULL;
}

