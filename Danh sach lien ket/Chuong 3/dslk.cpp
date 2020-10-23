#include <iostream>
#include<cstring>
using namespace std;

struct sinhvien
{
	int ngaysinh, thangsinh, namsinh;
	char hoten;
	char diachi;
	int mssv;
	
};
/*----------------------------------------*/
struct sinhvien_node
{
	sinhvien data;
	struct sinhvien_node *pnext;
};

struct DS
{
	sinhvien_node *pdau, *pcuoi;
};

void tao_list(DS &a)
{
	a.pdau = NULL;
	a.pcuoi == NULL;
};
/*----------------------------------------*/

// tao 1 node = x;
sinhvien_node getnode(sinhvien x)
{
	sinhvien_node *p = new sinhvien_node;
	
	if(p==NULL) exit(1);
	p -> data = x;
	p -> pnext = NULL;
	return *p;
};

void addhead(DS &l, sinhvien_node *p)
{
	if(l.pdau==NULL)
	{
		l.pdau = p;
		l.pcuoi = l.pdau;
	}
	else
	{
		p -> pnext = l.pdau;
		l.pdau = p;
	}
}
int main()
{
	return 0;
	sinhvien DSSV[40];
}
