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
	NODE *p = new NODE;
	if(p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
}

struct stack
{
	NODE *pTop;
};
typedef struct stack STACK;
void creatSTACK(STACK &s)
{
	s.pTop = NULL;
}
bool emty(STACK s)
{
	if(s.pTop == NULL)
	{
		return true;
	}
	else
	{
		return 0;
	}
}

void Push(STACK &s, NODE *p)
{
	if(emty(s) == true)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
}
void Pop(STACK &s, int x)
{
	if(emty(s))
	{
		return;
	}
	else
	{
		NODE *temp = s.pTop;
		x = temp->data;
		s.pTop = temp->pNext;
		delete temp;
	}
}
void output(STACK &s)
{
	if(emty(s)== true)
	{
		return;
	}
	NODE *p = s.pTop;
	int x;
	do
	{
		
		Pop(s,x);
		cout<<x<<" ";
	}
	while(emty(s)== false);
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
		Pop(s,a);
		Pop(s,b);
		cout<<a<<" "<<b;
		fibonacy+= a + b; // tinh tong so fibonacy
		
		NODE *temp = creatNODE(fibonacy);
		NODE *temp1 = creatNODE(a);
		NODE *temp2 = creatNODE(b);
		
		Push(s,temp);
		Push(s,temp2);
		Push(s,temp1);
	}
	return fibonacy;
}
int main()
{
	STACK s;
	creatSTACK(s);
	NODE *temp1 = creatNODE(0);
	NODE *temp2 = creatNODE(1);
	Push(s,temp1);
	Push(s,temp2);
	
	
	int n;
	cout<<"Nhap so Fibonacy can tinh : ";
	cin>>n;
	cout<<"So Fibonacy thu "<<n<<" la : "<<Fibonacy(s,n);
	return 0;
}
