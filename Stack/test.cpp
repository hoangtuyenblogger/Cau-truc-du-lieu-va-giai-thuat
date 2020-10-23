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
	while(!stack_is_null(s))
	{
		int x;
		pop_from_stack(s,x);
		cout<<x<<" ";
	}
}
int main()
{
	STACK s;
	createSTACK(s);
	input_stack(s);
	output_stack(s);
	return 0;
}
