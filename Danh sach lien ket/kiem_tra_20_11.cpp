/*-------------- Code by Hoang Kim Tuyen | 1824801040043 | D18HT01 -------------*/
/*-------------- Thu Dau Mot University -------------*/


#include <iostream>
using namespace std;

struct node 
{
	int data;
	node *pNext;	
};
typedef struct node NODE;

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
NODE *creatNODE(int x)
{
	NODE *p = new NODE;
	if(p==NULL)
	{
		cout<<"day bo nho "<<endl;
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
}

void creatLIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
/*--------------  Hoang Kim Tuyen | 1824801040043 | D18HT01 -------------*/
void addHead(LIST &l, NODE*p)
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

void delete_HEAD(LIST &l)
{
	NODE *temp = l.pHead->pNext;
	l.pHead = temp;
	delete temp;
}
void delete_TAIL(LIST &l)
{
	NODE *k = l.pHead;
	while(k != NULL)
	{
		if(k->pNext = l.pTail)
		{
			k->pNext = NULL;
			delete l.pTail;
			l.pTail = k;
		}
		k= k->pNext;
	}
}
void Push_to_list(LIST &l)
{
	int chucnang;
	do
	{
		cout<<"0. Dung nhap vao danh sach !"<<endl;
		cout<<"1. Tiep tuc nhap vao danh sach "<<endl;
		cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case(1):
				{
					int x;
					cout<<"Nhap gia tri can them vao : ";
					cin>>x;
					NODE * p = creatNODE(x);
					addTail(l, p); // them vao cuoi queue
					system("cls");
				}
		}
	}
	while(chucnang!=0);
}
void Pop_list(LIST l)
{
	NODE *k = l.pHead;
	while(k != NULL) // lay ra dau queue
	{
		cout<<k->data<<" ";
		k = k->pNext;
	}
}
void sort_list(LIST &l)
{
	NODE *k = l.pHead;
	while(k != NULL)
	{
		NODE *j = k->pNext; // Node j dung sau node k
		while(j != NULL)    // vong lap so sanh gia tri cua cac node voi node k
		{
			if(k->data > j->data)
			{
				// hoan doi gia tri giua node k va node j
				int temp = k->data; 
				k->data = j->data;
				j->data = temp;
			}
			j=j->pNext; // qua node tiep theo
		}
		k=k->pNext; // qua node tiep theo
	}
}
void insert_list(LIST &l)
{
	int x;
	cout<<"Nhap gia tri can chen vao danh sach : ";
	cin>>x;
	NODE *p = new NODE;
	 p = creatNODE(x); // tao node p chua gia tri x
	
	
	// them p vao danh sach tang theo truong du lieu
	if(p->data == l.pHead->data)
	{
		addHead(l,p);
		return;
	}
	if(p->data == l.pTail->data)
	{
		addTail(l,p);
		return;
	}
	
	NODE *k = l.pHead;
	while(k!= NULL)
	{
		NODE *j = k->pNext; // node j la node dung sau node k
		// so sanh gia tri cua p voi node k va j
		if(p->data > k->data && p->data < j->data)
		{
			// chen p vao giua k va j -------- k->next = p, p->next = j
			k->pNext = p;
			p->pNext = j;
		}
		
		k = k->pNext;
	}
}

int main()
{
	LIST danhsach;
	creatLIST(danhsach);
	Push_to_list(danhsach);
	cout<<"Danh sach vua nhap la : ";Pop_list(danhsach);cout<<endl;
	sort_list(danhsach);
	cout<<"Danh sach sau khi sap xep la: ";Pop_list(danhsach);cout<<endl;
	
	insert_list(danhsach);
	cout<<"Danh sach sau khi chen la : ";Pop_list(danhsach);cout<<endl;
	return 0;
}
