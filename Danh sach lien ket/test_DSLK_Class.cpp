#include <iostream>
using namespace std;
/* ------------------------------ dinh nghia NODE, LIST ------------------*/
class node
{
	public:
	int data;
	node *pNext;
};

typedef class node NODE;

class list
{
	public:
	NODE *pHead;
	NODE *pTail;
};
typedef class list LIST;

/* -------------------------------------cac ham ----------------------------------*/
NODE *createNODE(int x);
void createLIST(LIST &l);
void AddHead(LIST &l, NODE *p);
void AddTail(LIST &l, NODE *p);
void ADD_DATA_TO_LIST(LIST &l);
void PUT_DATA_FROM_LIST(LIST l);
void SORT_LIST(LIST &l);
void SwapNODE(NODE *a, NODE *b);





int main()
{
	LIST danhsach;
	createLIST(danhsach);
	ADD_DATA_TO_LIST(danhsach);
	
	cout<<"Day ban dau : ";
	PUT_DATA_FROM_LIST(danhsach);
	
	
	SORT_LIST(danhsach);
	cout<<"\nDay sau khi sap xep : ";
	PUT_DATA_FROM_LIST(danhsach);
	return 0;
}



NODE *createNODE(int x)
{
	NODE *p = new NODE;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void createLIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST &l, NODE *p)
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

void ADD_DATA_TO_LIST(LIST &l)
{
	int x=-1;
	while(x != 0)
	{
		/*------------------them x vao LIST cho den khi nao x = 0 thi dung lai--------------*/
		cout<<"Nhap gia tri can them vao danh sach : ";
		cin>>x;
		if(x == 0)
		{
			return;
		}
			
		// tao NODE chua x
		NODE *temp = createNODE(x);
		
		// them NODE vao LIST
		AddTail(l,temp);
		system("cls");	
	}
}

void PUT_DATA_FROM_LIST(LIST l)
{
	NODE *k = l.pHead;
	if(k == NULL)
	{
		cout<<"Danh sach rong ! "<<endl;
	}
	else
	{
		if(k == l.pTail) // neu list chi co 1 node thi in ra node do roi thoat
		{
			cout<<k->data;
			return;
		}
		while(k != NULL)
		{
			if(k == l.pTail)// neu la NODE cuoi cung thi xuat NODE cuoi cung ra roi ket thuc
			{
				cout<<k->data;
				return;
			}
			cout<<k->data<<"->";
			k = k->pNext;
		}
	}
}

void SwapNODE(NODE *a, NODE *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void SORT_LIST(LIST &l)
{	
	NODE *k = l.pHead;
	
	while(k != NULL)
	{
		NODE *j = k->pNext; // NODE j la NODE dung sau NODE k
		while(j!= NULL)
		{
			if(k->data > j->data)  // neu gia tri cua k > gia tri cua j
			{
				SwapNODE(k, j);    // thi doi gia tri cho k vs j
			}
			j = j->pNext;
		}
		k = k->pNext;
	}	
}
