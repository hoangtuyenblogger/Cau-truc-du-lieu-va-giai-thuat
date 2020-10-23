#include<iostream>
using namespace std;

struct node
{
	int data;
	node *pNext;
};
typedef struct node NODE;


NODE *creatNODE(int x)
{
	NODE * p = new NODE;
	if(p == NULL)
	{
		cout<<"khong du bo nho ";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

struct stack
{
	NODE *pTop;
};
typedef struct stack STACK;

void createSTACK(STACK &s)
{
	s.pTop = NULL;
}

bool stack_is_null(STACK s)
{
	if(s.pTop == NULL)
	{
		return true;
	}
	return false;
}

void push_to_stack(STACK &s, NODE *p)
{
	if(stack_is_null(s) == true)
	{
		s.pTop = p;
		return;
	}
	else
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
}


void pop_from_stack(STACK &s, int &x)
{
	if(stack_is_null(s) == true)
	{
		return;
	}
	NODE *p = s.pTop;
	x = p->data;
	s.pTop = p->pNext;
	delete p;
}

void top_from_stack(STACK s, int &x)
{
	if(stack_is_null(s) == true)
	{
		return;
	}
	x = s.pTop->data;
}

void input_stack(STACK &s)
{
	int x;
	int chucnang;
	do
	{
		cout<<"1. Nhap vao stack "<<endl;
		cout<<"2. Huy nhap vao stack "<<endl;
		cout<<"Chon chuc nang : ";
		cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case(1):
				{
					int a;
					cout<<"Nhap gia tri : ";
					cin>>a;
					
					NODE *p = creatNODE(a);
					push_to_stack(s,p);
					cout<<"Them thanh cong !"<<endl;
					break;
				}
		}
	}
	while(chucnang!=2);
}
void output_stack(STACK &s)
{
	if(stack_is_null(s) == true)
	{
		return;
	}
	NODE *p = s.pTop;
	int x;
	do
	{
		
		pop_from_stack(s,x);
		cout<<x<<" ";
	}
	while(stack_is_null(s)== false);
}


void output_stack_not_detele(STACK s)
{
	if(stack_is_null(s))
	{
		return;
	}
	else
	{
		NODE * p = s.pTop;
		while(stack_is_null(s) == false)
		{
			cout<<p->data<<" ";
			p = p->pNext;
		}
	}
}


int Sum(STACK s)
{
	int x;
	int tong=0;
	NODE *p = s.pTop;
	while(p != NULL)
	{
		tong = tong + p->data;
		p = p->pNext;
	}
	return tong;
}
int main()
{
	STACK s;
	createSTACK(s);
	input_stack(s);
	cout<<"Tong cac so trong stack la "<<Sum(s)<<endl;
	cout<<"Stack vua nhap la : ";output_stack_not_detele(s);
	
	return 0;
}
