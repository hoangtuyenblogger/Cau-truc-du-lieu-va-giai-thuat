#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct sinhvien
{
	char *hoten = new char[255];
	char *mssv = new char[15];
	int namsinh;
	char *diachi = new char[255];
	/*	
	sinhvien()
	{
		hoten = "Ten ne";
		mssv = "MSSV ne";
		namsinh = 2000;
		diachi = "Dia chi ne";
	} */
	
};

// ham nhap vao sinh vien
istream& operator >> (istream &in, sinhvien &a)
{
	cout<<"Nhap ho ten :";
	fflush(stdin); // xoa vung dem
	in.get(a.hoten,255);
	
	
	cout<<"Nhap MSSV : ";
	fflush(stdin); // xoa vung dem
	in>>a.mssv;
	
	
	cout<<"Nhap nam sinh :";
	in >>a.namsinh;
	
	cout<<"Nhap dia chi :";
	fflush(stdin); // xoa vung dem
	in.get(a.diachi,255);
}


 // ham xuat sinh vien
 ostream& operator <<(ostream&out, sinhvien a)
 {
 	out<<a.hoten<<"\t"<<a.mssv<<"\t"<<a.namsinh<<"\t"<<a.diachi;

 }
// Node chua thong tin va con tro toi phan tu tiep theo
struct Snode
{
	sinhvien data;
	Snode *pnext;	
};

// cap phat cho 1 node khi can ---> tra ve 1 Snode
Snode* getnode(sinhvien a)
{
	Snode *p = new Snode; // tao 1 con tro Snode
	
	// lay thong tin tu sinhvien a vao con tro p
	p->data = a;
	p->pnext = NULL;
	
	return p;
}

// tao 1 danh sach lien ket
struct danhsach
{
	Snode *node_dau;
	Snode *node_cuoi;
	danhsach()
	{
	}
	
	danhsach(Snode *head, Snode *tail)
	{
		this->node_dau->data = head->data;
		this->node_dau->pnext = tail;
		
		this->node_cuoi = tail;
		
	}
};
// them 1 node vao dau danh sach
void addhead(danhsach list, Snode *a)
{
	a->pnext = list.node_dau;
	list.node_dau = a;
}








int main()
{
	sinhvien sv1, sv2, sv3;
	Snode *a, *b, *c;
	cin>>sv1;
	cin>>sv2;	
	a = getnode(sv1);
	b = getnode(sv2);
	//tao danh sach co a va b
	danhsach list(a,b);
	cout<<list.node_dau->data<<endl;
	cout<<list.node_cuoi->data;
	
/*
	cin>>sv3;
	c = getnode(sv3);
	// them c vao danh sach
	addhead(list, c);
	cout<<list.node_dau->data;
	cout<<list.node_cuoi->data;
*/
	return 0;
}
