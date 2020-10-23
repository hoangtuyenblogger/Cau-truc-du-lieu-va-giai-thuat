#include <iostream>
using namespace std;

class node
{
	public:
	int data;
	class node *pNext;
};
typedef class node NODE;

class list
{
	public:
	NODE* pHead;
	NODE* pTail;
};
typedef class list LIST;

void createLIST(LIST &l);
NODE *createNODE(int x);
void addHead(LIST &l, NODE *p);
void addTail(LIST &l, NODE *p);
void ADD_P_TO_LIST(LIST &l, NODE *p);




void nhap_data_DSLK(LIST &l);
void xuat_data_DSLK(LIST l);


int main()
{
	LIST danhsach;
	createLIST(danhsach);


	int chucnang;
	do
	{
		cout<<"0. Thoat !!!"<<endl;
		cout<<"1. Nhap vao danh sach "<<endl;
		cout<<"2. Xuat danh sach "<<endl;
		cout<<"3. Chen vao danh sach "<<endl;
		cout<<"\nChon chuc nang : ";
		cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case(1):
				{
					nhap_data_DSLK(danhsach);
					break;
				}
			case(2):
				{
					xuat_data_DSLK(danhsach);
					break;
				}
			case(3):
				{
					int x;
					cout<<"\nNhap gia tri can them vao : ";
					cin>>x;
					system("cls");
					NODE *k = createNODE(x);
					
					ADD_P_TO_LIST(danhsach,k);
					break;
				}
			default:
				{
					cout<<"Chuc nang khong dung ! "<<endl;
					break;
				}
		}
	}
	while(chucnang!= 0);
	return 0;
}


void createLIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *createNODE(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x; // dua d? li?u c?a bi?n x vào data c?a cái Node p
	p->pNext = NULL; // kh?i t?o node p nhung node p chua có liên k?t d?n node nào h?t

	return p;
}

void addHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // tro dia chi cua p vao NODE dau tien la pHead
		l.pHead = p; 
	}
}

void addTail(LIST &l, NODE *p)
{
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

void nhap_data_DSLK(LIST &l)
{
		int x;
		do
		{
			cout<<"Nhap gia tri : ";
		cin>>x;
		if(x<1)
		{
			return;
		}
		NODE *k = createNODE(x);
		addTail(l,k);
		system("cls");	
		}
		while((int)x);
			
}

void xuat_data_DSLK(LIST l)
{
	if(l.pHead == NULL)
	{
		cout<<"Danh sach rong !!!"<<endl;
	}
	else
	{       
		for(NODE *i = l.pHead; i != NULL; i = i->pNext)
		{
			cout<<i->data<<" ";
		}
		cout<<endl;
	}
}


void ADD_P_TO_LIST(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		addHead(l,p);
		return;
	}
	if(p->data <= l.pHead->data)
	{
		addHead(l,p);
		cout<<"Da them vao dau danh sach"<<endl;
		return;
	}
	if(p->data >= l.pTail->data )
	{
		addTail(l,p);
		cout<<"Da them vao cuoi danh sach"<<endl;
		return;
	}
	for(NODE *i = l.pHead;i->pNext != NULL; i= i->pNext) 
	{
		NODE *j = new NODE;
		j = i->pNext;
		if(p->data > i->data && p->data < j->data)
		{
			i->pNext = p;
			p->pNext = j;
			cout<<"Da them thanh cong ! "<<endl;
			return;
		}
	}
	
}
