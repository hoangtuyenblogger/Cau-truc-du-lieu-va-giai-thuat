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
	int a=0;
	while(a != -1)
	{
		cout<<"Nhap gia tri (nhap so -1 de thoat !) : ";
		cin>>a;
		if(a == 0 )
		{
			return;
		}
		NODE *p = creatNODE(a);
		push_to_stack(s,p);
		system("cls");
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


void OCT_TO_BIN(STACK &s, int x)
{
	int temp, count=0;
	do
	{
		temp = x % 2; // lay so du phep chia x / 2
		NODE *p = creatNODE(temp);   // tao node p luu gia tri so du 
		push_to_stack(s,p);          // them node p vao stack
		x = x/ 2;                    // cap nhat lai gia tri x
		count++;
	}
	while(x != 0);
	
	if(count < 8) // lam day stack 
	{
		for(int i=0;i<(8-count); i++)
		{
			NODE *k = creatNODE(0);
			push_to_stack(s,k);
		}
	}
	
}

void xuat_stack_chua_nhi_phan(STACK &s)
{
	int count=0;
	int bin;
	NODE * p= s.pTop;
	while(!stack_is_null(s))
	{
		pop_from_stack(s,bin);
		count++;
		
		if(count == 4)
		{
			cout<<bin<<" ";
		}
		else
		{
			cout<<bin;
		}
	}
}

void xuat_so_nhi_phan(STACK s)
{
	
	NODE *k = s.pTop;
	while(!stack_is_null(s)) // duyet het vong while - chuyen cac gia tri trong stack thanh nhi phan roi bo vao stack tuong ung
	{
		STACK temp;
		createSTACK(temp);
		
		int count =0;
		int a = k->data;
		
		OCT_TO_BIN(temp,a); // chuyen gia tri trong node k sang dang nhi phan roi bo vao STACK temp
		cout<<a<<": ";
		xuat_stack_chua_nhi_phan(temp);
		cout<<endl;
		k = k->pNext; // qua gia tri tiep theo
	}
}

int Fibonacy(STACK &s, int n)
{
	int fibonacy=0;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	for(int i=2;i<n;i++)
	{
		int a, b;
		pop_from_stack(s,a);
		pop_from_stack(s,b);
		cout<<a<<" "<<b;
		fibonacy+= a + b; // tinh tong so fibonacy
		
		NODE *temp = creatNODE(fibonacy);
		NODE *temp1 = creatNODE(a);
		NODE *temp2 = creatNODE(b);
		
		push_to_stack(s,temp);
		push_to_stack(s,temp2);
		push_to_stack(s,temp1);
	}
	return fibonacy;
}

int main()
{
	STACK s;
	createSTACK(s);
	input_stack(s);
	xuat_so_nhi_phan(s);
	
	return 0;
}
