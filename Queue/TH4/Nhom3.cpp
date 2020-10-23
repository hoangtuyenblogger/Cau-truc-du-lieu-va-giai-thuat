
#include<iostream>
#include<fstream>
using namespace std;

/*
Nh?p danh s�ch queue ch?a c�c s? nguy�n, sau d� xu?t ra m�n h�nh c�c gi� tr? s? nguy�n d�

*/

// khai b�o c?u tr�c c?a 1 c�i node trong queue
struct node
{
	int data; // queue dang ch?a c�c s? nguy�n
	struct node *pNext; // con tr? li�n k?t gi?a c�c node v?i nhau
};
typedef struct node NODE;

// khai b�o c?u tr�c c?a queue
struct queue
{
	NODE *front; //  con tro dau
	NODE *end; // con tro cu?i 
};
typedef struct queue QUEUE;

// h�m kh?i t?o queue
void KhoiTaoQueue(QUEUE &q)
{
	q.front = NULL;
	q.end = NULL;
}

// h�m kh?i t?o 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // th�m gi� tr? c?a bi?n x v�o trong data c?a c�i node
	p->pNext = NULL;
	return p;
}

// =============== KI?M TRA QUEUE C� R?NG HAY KH�NG ===============
bool IsEmpty(QUEUE q)
{
	// n?u danh s�ch r?ng
	if (q.front == NULL)
	{
		return true;
	}
	return false;// danh s�ch c� ph?n t?
}

// =============== TH�M 1 PH?N T? V�O CU?I QUEUE- FIFO ===============
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// n?u danh s�ch r?ng
	if (IsEmpty(q) == true)
	{
		q.front = q.end = p; // node p ch�nh l� node d?u v� node cu?i
	}
	else // them vao cuoi hang doi
	{
		q.end->pNext = p;
		q.end = p; 
	}
	return true;
}

// =============== L?Y PH?N T? �?U QUEUE V� H?Y N� �I - FIFO ===============
bool Pop(QUEUE &q, int &x) // x ch�nh l� gi� tr? c?n l?y trong node
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else // lay p tu dau hang doi 
	{
		NODE *p = q.front; // node p ch�nh l� node th? m?ng d? t� n?a ch�ng ta x�a n� di
		x = p->data; // g�n gi� tr? c?a node d?u stack v�o bi?n x	
		q.front = q.front->pNext; // c?p nh?t node d?u queue l� node ti?p theo	
		delete p; // x�a node d?u queue v?a l?y 

	}
	return true;// l?y ph?n t? d?u queue th�nh c�ng
}


// =============== XEM TH�NG TIN C?A PH?N T? �?U QUEUE - KH�NG C� H?Y N� �I NH� ===============
bool Top(QUEUE q, int &x) // x ch�nh l� gi� tr? c?n l?y ra d? xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.front->data; // l?y gi� tr? c?a ph?n t? d?u queue ra d? xem
	return true;
}

// h�m xu?t danh s�ch queue
void XuatQueue(QUEUE q)
{
	if(IsEmpty(q))
	{
		cout<<"Queue rong ! "<<endl;
	}
	NODE *p = q.front;
	while (p != NULL)
	{
		cout<<p->data<<" ";
		p = p->pNext;
	}

}

// h�m nh?p danh s�ch c�c s? nguy�n trong queue
void NhapQueue(QUEUE &q)
{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(q, p);
}

int Sum(QUEUE q)
{
	int kq=0;
	NODE *p = q.front;
	while(p!= NULL)
	{
		kq+=p->data;
		p = p->pNext;
	}
	return kq;
}

void nhap_tu_ban_phim(QUEUE &q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao queue - Push";
		cout << "\n\t2. Xuat danh sach queue ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
		cout << "\n\t4. Tinh Tong Queue";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			NhapQueue(q);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			cout<<endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			int a;
			Top(q,a);
			cout << "\nPhan tu dau queue la: " << a;
			cout<<endl;
			system("pause");
		}
		else if(luachon == 4)
		{
			int KQ;
			KQ = Sum(q);
			cout<<"Tong queue la : "<<KQ;
			cout<<endl;
			break;
		}
	}

	system("pause");
}

void nhap_xuat_file(QUEUE q)
{
	fstream f;
	int a;
	f.open("input.txt",ios::in);
	while(!f.eof())
	{
		f>>a;
		NODE *p = KhoiTaoNode(a);
		Push(q,p);
	}
	
	int sum = Sum(q);
	
	fstream f_out;
	f_out.open("output.txt",ios::out);
	f_out<<sum;
	
	
	
	
	
	// kiem tra
	if(sum>0)
	{
		cout<<"Da ghi vao file !"<<endl;
		system("pause");
	}
}
int main()
{
	QUEUE q;
	KhoiTaoQueue(q);

	int chucnang;
	do
	{
		cout<<"\t\t\t1. Nhap va tinh tong Queue tu ban phim "<<endl;
		cout<<"\t\t\t2. Nhap tu file Input.txt va xuat tong Queue vao file Output.txt "<<endl;
		cout<<"\nChon chuc nang : ";
		cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case(1):
				{
					nhap_tu_ban_phim(q);
					break;
				}
			case(2):
				{
					nhap_xuat_file(q);
				}
		}
		
	}
	while(chucnang!=0);

	system("pause");
	return 0;
}
