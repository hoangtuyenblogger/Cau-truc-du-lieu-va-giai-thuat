#include<iostream>
#include<string>
using namespace std;

struct sinhvien
{
	string ten;
	float diem_tb;
};
void nhap_thong_tin(sinhvien &sv)
{
	cout<<"Nhap ten sinh vien :";
	getline(cin,sv.ten);
	cout<<"Nhap diem trung binh :";
	cin>>sv.diem_tb;
}
struct node
{
	int data;
	node *pNext;
};
typedef struct node NODE;

NODE *creatNODE(int x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		cout<<"Khong du bo nho !";
		return NULL;
	}
	
	p->data = x;
	p->pNext = NULL;
	return p;
}
struct list
{
	NODE *pHead;
	NODE *pTail;	
};
typedef struct list LIST;

void creatLIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void addHead(LIST &l, int x)
{
	NODE *p = creatNODE(x);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext == l.pHead;
		l.pHead = p;	
	}
}
void addTail(LIST &l, int x)
{
	NODE *p = creatNODE(x);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void input_list(LIST &l)
{
	cout<<"Nhap gia tri can them vao danh sach : ";
	int x;
	cin>>x;
	addTail(l,x);
}
void output_list(LIST l)
{
	if(l.pHead == NULL)
	{
		cout<<"Danh sach rong !\n";
		return;
	}
	for(NODE *i= l.pHead;i!= NULL;i=i->pNext)
	{
		cout<<i->data<<" ";
	}
}

void xoa_dau(LIST &l)
{
	NODE *p = l.pHead->pNext;
	delete l.pHead;
	l.pHead = p;
}
void xoa_cuoi(LIST &l)
{
	for(NODE *i = l.pHead;i!= NULL;i = i->pNext)
	{
		if(i->pNext == l.pTail)
		{
			i->pNext = NULL;
			delete l.pTail;
			l.pTail = i;
		}
	}
}
void xoa(LIST &l, int x)
{
	if(l.pHead->data == x)
	{
		xoa_dau(l);
		return;
	}
	if(l.pTail->data == x)
	{
		xoa_cuoi(l);
		return;
	}
	else
	for(NODE *i = l.pHead; i != NULL;i = i->pNext)
	{
		NODE *j = i->pNext; // node j la node dung sau node i
		if(j->data == x)
		{
			NODE *temp = j->pNext;
			i->pNext = temp;
			delete j;

		}
	}
}

void xoa_khoang_m_n(LIST &l, int m, int n)
{
	if((l.pHead->data == m && l.pTail->data == n) || (l.pHead->data == m && l.pTail->data == n))
	{
		xoa_dau(l);
		xoa_cuoi(l);
		return;
	}
	for(NODE *i = l.pHead;i!= NULL;i=i->pNext)
	{
		NODE *j = i->pNext;
		if(j->data == m )
		{
			NODE *k = j->pNext;
			NODE *p = k->pNext;
			xoa(l,k->data);
			xoa(l,p->data);
		}
	}
}
int main()
{
	LIST danhsach;
	creatLIST(danhsach);
	int chucnang=-1;
	
	do
	{
		cout<<endl;
		cout<<"0. Thoat !\n";
		cout<<"1. Nhap vao danh sach\n";
		cout<<"2. Xuat danh sach\n";
		cout<<"3. Xoa gia tri khoi danh sach\n";
		cout<<"4. Xoa gia tri trong khoang m - n\n";
		cout<<"Chon chuc nang : ";
		cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case(1):
				{
					input_list(danhsach);
					break;
				}
			case(2):
				{
					cout<<"Danh sach la : ";
					output_list(danhsach);
					cout<<endl;
					break;
				}
			case(3):
				{
					int a;
					cout<<"\nNhap gia tri can xoa : ";
					cin>>a;
					xoa(danhsach,a);
					cout<<"Da xoa "<<a<<" khoi danh sach !\n";
					break;
				}
			case(4):
			{
				int m, n;
				cout<<"Nhap doan m - n can xoa : ";
				cin>>m>>n;
				xoa_khoang_m_n(danhsach,m,n);
				break;
			}
			case(0):
				{
					cout<<"Da thoat !\n";
					break;
				}
			default:
				{
					cout<<"Chuc nang khong hop le !\n";
					break;
				}
		}
	}
	while(chucnang!=0);
	return 0;
}
