#include<iostream>
#include <fstream>
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
	int n;
	int x;
	fstream f;
	f.open("input.txt",ios::in);
	f>>n;
	for(int i=0;i<n;i++)
	{
		f>>x;
		NODE *p = creatNODE(x);
		push_to_stack(s,p);
	}
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
	// xuat file output.txt
	fstream f;
	f.open("output.txt",ios::out);
	f<<Sum(s);
	f.close();
	cout<<"Da ghi vao file ! "<<endl;
	
	return 0;
}
