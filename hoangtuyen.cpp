#include<iostream>
#include"hoangtuyen.h"
#include<math.h>
using namespace std;



/*------------------------------------------- Bắt đầu điểm------------------------------------------*/
diem::diem()
{
	x=0;
	y=0;
}

diem::diem(int _x,int _y)
{
	x=_x;
	y=_y;
}

diem::diem(diem &d)
{
	x=d.x;
	y=d.y;
}

diem::~diem()
{
}

void diem::nhap()
{
	cout<<"Nhap toa do x, y";
	cin>>x>>y;
}
void diem::xuat()
{
	cout<<"diem vua nhap co toa do la : ";
	cout<<"x="<<x<<" y="<<y;
}
double diem::kc(diem &M)
{
	double kq = 0.0;
	double v =pow((M.x-x),2) + pow((M.y-y),2);
	kq=sqrt(v);
	return kq;
}
/*------------------------------------------- kết thúc điểm------------------------------------------*/


/*------------------------------------------- Bắt đầu đường tròn------------------------------------------*/
duongtron::duongtron()
{
	r=1.0;
	pi=3.14;
}
duongtron::duongtron(float &bankinh)
{
	r=bankinh;
	pi=3.14;
}
void duongtron::nhap()
{
	cout<<"Nhap ban kinh cua duong tron R = ";
	cin>>r;
}
void duongtron::xuat()
{
	cout<<"Nhap ban kinh cua duong tron la R = "<<r;	
}
duongtron::duongtron(duongtron &d)
{
	r=d.r;
}

duongtron::~duongtron()
{
}


float duongtron::c()
{
	float  chuvi= 0.0;
	chuvi=2*r*3.14;
	return chuvi;
}
float duongtron::s()
{
	float dientich= 0.0;
	dientich=r*r*3.14;
	return dientich;
}

float duongtron::c(float&bankinh)
{
	r=bankinh;
	float chuvi = 0.0;
	chuvi=r*2*3.14;
	return chuvi;
}
float duongtron::s(float&bankinh)
{
	r=bankinh;
	float dientich = 0.0;
	dientich=r*r*3.14;
	return dientich;
}


float duongtron::cHT(diem &i, diem &m)
{
	r=float(i.kc(m));
	return c(r);
}

float duongtron::sHT(diem &i, diem &m)
{
	r=float(i.kc(m));
	return s(r);
}
/*------------------------------------------ Kết thúc đầu đường tròn------------------------------------------*/





/*--------------------------------- Bắt đầu phân số ------------------------------*/
phanso::phanso()
{
	tuso=0;
	mauso=0;
}
phanso::~phanso()
{
	cout<<endl;
}
int phanso::ucln(int a, int b)
{
	if(b==0) return a;
	else return ucln(b,a%b);
}
void phanso::toigian()
{
	int UCLN=ucln(tuso,mauso);
    tuso=tuso/UCLN;
    mauso=mauso/UCLN;
    if(mauso<0)
    {
        tuso*=-1;
        mauso*=-1;
    }
}
void phanso::nhap()
{
	cout<<"Nhap tu so: ";
	cin>>tuso;
	cout<<"Nhap mau so: ";
	cin>>mauso;
	 // kiem tra mau so khac 0
	while(mauso==0)
	{
		cout<<"Mau so khong duoc bang 0, nhap lai mau so : ";
		cin>>mauso;
	}
    toigian();

}

void phanso::xuat()
{
	if(mauso==1)
		{cout<<tuso<<endl;}
	else
		{
			cout<<tuso<<"/"<<mauso<<endl;
			cout<<thapphan();
		}
}

phanso phanso::cong(phanso &b)
{
	phanso temp;
	temp.tuso=(tuso+b.mauso)+(b.tuso*mauso);
	temp.mauso=mauso*b.mauso;
	return temp;
}

phanso phanso::operator+(phanso &b)
{
	phanso temp;
	temp.tuso=(tuso*b.mauso)+(b.tuso*mauso);
	temp.mauso=mauso*b.mauso;
	temp.toigian();
	return temp;
}
phanso phanso::operator-(phanso &b)
{
	phanso temp;
	temp.tuso=(tuso*b.mauso)-(b.tuso*mauso);
	temp.mauso=mauso*b.mauso;
	temp.toigian();
	return temp;
}
phanso phanso::operator*(phanso &b)
{
	phanso temp;
	temp.tuso=tuso*b.tuso;
	temp.mauso=mauso*b.mauso;
	temp.toigian();
	return temp;
}

phanso phanso::operator/(phanso &b)
{
	phanso temp;
	temp.tuso=tuso*b.mauso;
	temp.mauso=mauso*b.tuso;
	temp.toigian();
	return temp;
}
float phanso::thapphan()
{
    return float(tuso)/mauso;
}
/*---------------------------------------------- hết phân số------------------------------------------------*/

/*------------------------ Kiếm tra số nguyên tố, số hoàn hảo, số chính phương-------------------*/
bool snt(int a)
{
	if(a<2)
		return false;
	else
	{
		if(a==2)
			return true;
		else
		{
			if(a%2==0) return false;
			else
			{
				for(int i=2;i<a;i++)
				{
					if(a%i==0) return false;
				}
			}
			
		}
	}
	return true;
}

bool sht(int a)
{
	int s=1;
	if(a<6) return false;
	else
	{
		for(int i=2;i<a;i++)
		{
			if(a%i==0)
				s+=i;
		}
		if(s==a) return true;
	}
	return false;
	
}
bool scp(int a)
{
	int k=sqrt(a);
	cout<<"k="<<k;
	if(k==sqrt(a)) return true;
	return false;
}
/*------------------------ Kiếm tra số nguyên tố, số hoàn hảo, số chính phương-------------------*/