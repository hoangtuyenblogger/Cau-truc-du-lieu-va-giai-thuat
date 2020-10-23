#include <iostream>
using namespace std;
#include<cstring>

struct sinhvien
{
 string hoten;
 string mssv;
 int namsinh;
 string lop;
};

struct node
{
 sinhvien data;
 struct node *pNext;
};
typedef struct node NODE; // doi node thanh NODE co the chay tren c, c++

struct list
{
 NODE *pHead;
 NODE *pTail;
};
typedef struct list LIST;

void nhap_thong_tin_sinh_vien(sinhvien &sv);
istream&operator >> (istream&nhap, sinhvien &sv);
void xuat_thong_tin_sinh_vien(sinhvien sv);
ostream&operator << (ostream&xuat, sinhvien sv);

void creatLIST(LIST &l);
NODE *creatNODE(sinhvien sv);

void addHead(list &l, NODE *p);
void addTail(list &l, NODE *p);
void nhap_danh_sach(LIST &l);
void xuat_danh_sach(LIST l);


int main()
{
 LIST danhsach1;
 creatLIST(danhsach1);
 nhap_danh_sach(danhsach1);
 xuat_danh_sach(danhsach1);
 
 return 0;
}



void nhap_thong_tin_sinh_vien(sinhvien &sv)
{
 cout<<"Nhap ten sinh vien : ";
 getline(cin,sv.hoten);
 
 cout<<"Nhap MSSV : ";
 cin.ignore();
 getline(cin,sv.mssv);
 
 cout<<"Nhap nam sinh : ";
 cin>>sv.namsinh;
 
 cin.ignore();
 cout<<"Nhap lop : ";
 getline(cin,sv.lop);
}

void xuat_thong_tin_sinh_vien(sinhvien sv)
{
 cout<}



istream&operator >> (istream&nhap, sinhvien &sv)
{
 cout<<"Nhap ten sinh vien : ";
 getline(cin,sv.hoten);
 
 cout<<"Nhap MSSV : ";
 cin.ignore();
 getline(cin,sv.mssv);
 
 cout<<"Nhap nam sinh : ";
 cin>>sv.namsinh;
 
 cin.ignore();
 cout<<"Nhap lop : ";
 getline(cin,sv.lop);
}

ostream&operator << (ostream&xuat, sinhvien sv)
{
 xuat<}



void creatLIST(LIST &l)
{
 l.pHead = NULL;
 l.pTail = NULL;
}

NODE *creatNODE(sinhvien sv)
{
 NODE *p = new NODE;
 p->data = sv;
 p->pNext = NULL; 
}


void addHead(list &l, NODE *p)
{
 if(l.pHead == NULL)    // neu NODE dau tien bang  NULL, co nghia la LIST chua co NODE nao het
 {
  l.pHead = l.pTail = p;  // thi NODE dau cung la NODE cuoi va bang p ( NODE dau = NODE cuoi = p )
 }
 else                        // nguoc lai, neu lIST da co NODE
 {
  p->pNext = l.pHead;   // do chen vao dau LIST, nen con tro pNext cua p se tro vao NODE dau tien
  l.pHead = p;       // cap nhat lai NODE dau tien chinh la p
 }
}

void addTail(LIST &l, NODE *p)
{
 if(l.pHead == NULL)    // neu NODE dau tien bang  NULL, co nghia la LIST chua co NODE nao het
 {
  l.pHead = l.pTail = p;  // thi NODE cuoi cung la NODE cuoi va bang p ( NODE dau = NODE cuoi = p )
 }
 else      // nguoc lai, neu lIST da co NODE
 {
  l.pTail->pNext = p;
  l.pTail = p;
 }
}


void nhap_danh_sach(LIST &l)
{
 int kt=0;
 do
 {
  system("cls");
  cout<<"1. Tiep tuc thong tin vao danh sach "<  cout<<"2. Thoat !!! "<  cin>>kt;
  cin.ignore();
  switch(kt)
  {
   case(1):
    {
     cout<<"=================================Nhap data cho NODE sv=============================  \n";
     // tao 1 sinh vien & nhap thong tin cho sinh vien 
     sinhvien a;
     cin>>a;
  
     NODE *p = creatNODE(a); // them sinhvien a vao NODE p
     addHead(l,p);           // them NODE p vao danh sach
     break;
    }
    case(2):
     break;
  } 
 }
 while( kt!= 2);
 
}

void xuat_danh_sach(LIST l)
{
 if(l.pHead == NULL) // neu danh sach chua co gi
 {
  cout<<"Danh sach rong !"< }
 else
 {
  for(NODE *i = l.pHead; i != NULL; i = i->pNext)
  {
   //xuat_thong_tin_sinh_vien(i->data);
   cout << i->data;
   cout<  }
 }
}
