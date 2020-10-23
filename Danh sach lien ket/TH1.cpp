#include <iostream>
using namespace std;
#include<cstring>

struct sinhvien
{
	char *hoten = new char[256];
	char *mssv = new char [10]; // 9 ki tu + ki tu /0
	int namsinh;
	char *lop = new char[10] ;
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

void nhap_thong_tin_sinh_vien(sinhvien &sv);
istream&operator >> (istream&nhap, sinhvien &sv);
void xuat_thong_tin_sinh_vien(sinhvien sv);
ostream&operator << (ostream&xuat, sinhvien sv);

void creatLIST(LIST &l);
NODE *creatNODE(sinhvien sv);

void addHead(list &l, NODE *p);
void addTail(list &l, NODE *p);
void add_sau_q(NODE *p, NODE *q, LIST &l);
NODE *searchINFO(LIST l, char *MSSV);
void searchINFO_DELETE(LIST &l, char *HOTEN);
void delete_pHead(LIST &l);
void delete_pTail(LIST &l);



void nhap_danh_sach(LIST &l);
void xuat_danh_sach(LIST l);

void menu();


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
		cout<<"3. Xoa thong tin sinh vien "<<endl;
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
					char *ten = new char[256];
					cout<<"Nhap ho ten can xoa : ";
					cin.ignore();
					cin.getline(ten, 256);
					searchINFO_DELETE(danhsach1, ten);
				}
				
		}
		
		
	}
	while(chucnang!=0);
	
	
	
	return 0;
}



void nhap_thong_tin_sinh_vien(sinhvien &sv)
{
	cout<<"Nhap ten sinh vien : ";
	cin.getline(sv.hoten,256);
	cin.ignore();
	
	cout<<"Nhap MSSV : ";
	cin.getline(sv.mssv,9);
	
	cout<<"Nhap nam sinh : ";
	cin>>sv.namsinh;
	
	cin.ignore();
	cout<<"Nhap lop : ";
	cin.getline(sv.lop,10);
}

void xuat_thong_tin_sinh_vien(sinhvien sv)
{
	cout<<sv.hoten<<"\t"<<sv.namsinh<<"\t"<<sv.mssv<<"\t"<<sv.lop;
}



istream&operator >> (istream&nhap, sinhvien &sv)
{
	cout<<"Nhap ten sinh vien : ";
	cin.getline(sv.hoten,256);
	fflush(stdin);
	
	cout<<"Nhap MSSV : ";
	cin.getline(sv.mssv,9);
	
	cout<<"Nhap nam sinh : ";
	cin>>sv.namsinh;
	
	
	cin.ignore();
	cout<<"Nhap lop : ";
	cin.getline(sv.lop,10);
}

ostream&operator << (ostream&xuat, sinhvien sv)
{
	xuat<<sv.hoten<<"\t"<<sv.namsinh<<"\t"<<sv.mssv<<"\t"<<sv.lop;
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
					cin>>a;
		
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
			//xuat_thong_tin_sinh_vien(i->data);
			cout << i->data;
			cout<<endl;
		}
	}
}

void add_sau_q(NODE *p, NODE *q, LIST &l)
{
	if(q != NULL)
	{
		p->pNext = q->pNext;
		q->pNext = p;
		if(l.pTail == p)
		{
			l.pTail = p;
		}
	}
	else
	{
		addHead(l,p);
	}
}

void delete_pHead(LIST &l)
{
	NODE *temp = l.pHead->pNext; // luu dia chi NODE sau pHead
	delete l.pHead;
	l.pHead = temp;
}
void delete_pTail(LIST &l)
{
	NODE *temp = l.pTail;
			for(NODE *i = l.pHead; i->pNext != NULL; i = i->pNext)
			{
				if(i->pNext == temp)
				{
					i->pNext = NULL;
					l.pTail = i;
					delete temp;
					return;
				}
			}
}

NODE *searchINFO(LIST l, char* HOTEN)
{
	for(NODE *i = l.pHead; i->pNext != NULL; i = i->pNext)
	{
		int kt = stricmp(i->data.hoten,HOTEN);
		if(kt == 0)
		{
			return i;
		}
	}
	return NULL;
}


void searchINFO_DELETE(LIST &l, char *HOTEN)
{
	NODE *k = searchINFO(l,HOTEN);
	if(k == NULL)
	{
		cout<<"Khong tim thay !"<<endl;
		return;
	}
	
	
	 if(k == l.pHead) // xoa dau
		{
			delete_pHead(l);
			cout<<"Da xoa thanh cong ! "<<endl;
		}
		
	else if(k == l.pTail->pNext) // xoa cuoi
		{
			delete_pTail(l);
			cout<<"Da xoa thanh cong ! "<<endl;
		}
	
	else
	{
			for(NODE *i = l.pHead; i->pNext != NULL; i = i->pNext)
			{
				if(i->pNext == k )
					{
						i->pNext = k->pNext;
						delete k; 
						cout<<"Da xoa thanh cong ! "<<endl;
						return;
					}
					
			}
			cout<<"Khong tim thay thong tin, khong the xoa ! "<<endl;
	}
}


