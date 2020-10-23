
#include<iostream>
#include<fstream>
using namespace std;

/*
Nh?p danh sách queue ch?a các s? nguyên, sau dó xu?t ra màn hình các giá tr? s? nguyên dó

*/

// khai báo c?u trúc c?a 1 cái node trong queue
struct node
{
	int data; // queue dang ch?a các s? nguyên
	struct node *pNext; // con tr? liên k?t gi?a các node v?i nhau
};
typedef struct node NODE;

// khai báo c?u trúc c?a queue
struct queue
{
	NODE *front; //  con tro dau
	NODE *end; // con tro cu?i 
};
typedef struct queue QUEUE;

// hàm kh?i t?o queue
void KhoiTaoQueue(QUEUE &q)
{
	q.front = NULL;
	q.end = NULL;
}

// hàm kh?i t?o 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá tr? c?a bi?n x vào trong data c?a cái node
	p->pNext = NULL;
	return p;
}

// =============== KI?M TRA QUEUE CÓ R?NG HAY KHÔNG ===============
bool IsEmpty(QUEUE q)
{
	// n?u danh sách r?ng
	if (q.front == NULL)
	{
		return true;
	}
	return false;// danh sách có ph?n t?
}

// =============== THÊM 1 PH?N T? VÀO CU?I QUEUE- FIFO ===============
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// n?u danh sách r?ng
	if (IsEmpty(q) == true)
	{
		q.front = q.end = p; // node p chính là node d?u và node cu?i
	}
	else // them vao cuoi hang doi
	{
		q.end->pNext = p;
		q.end = p; 
	}
	return true;
}

// =============== L?Y PH?N T? Ð?U QUEUE VÀ H?Y NÓ ÐI - FIFO ===============
bool Pop(QUEUE &q, int &x) // x chính là giá tr? c?n l?y trong node
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else // lay p tu dau hang doi 
	{
		NODE *p = q.front; // node p chính là node th? m?ng d? tí n?a chúng ta xóa nó di
		x = p->data; // gán giá tr? c?a node d?u stack vào bi?n x	
		q.front = q.front->pNext; // c?p nh?t node d?u queue là node ti?p theo	
		delete p; // xóa node d?u queue v?a l?y 

	}
	return true;// l?y ph?n t? d?u queue thành công
}


// =============== XEM THÔNG TIN C?A PH?N T? Ð?U QUEUE - KHÔNG CÓ H?Y NÓ ÐI NHÉ ===============
bool Top(QUEUE q, int &x) // x chính là giá tr? c?n l?y ra d? xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.front->data; // l?y giá tr? c?a ph?n t? d?u queue ra d? xem
	return true;
}

// hàm xu?t danh sách queue
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

// hàm nh?p danh sách các s? nguyên trong queue
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
