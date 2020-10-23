#include <iostream>
using namespace std;
#include<string>
#include<math.h>

string OTC_TO_BIN(int x)
{
	string temp;
	for(int i=0;i<8;i++)
	{
		if(x-=pow(2,i > 0))
		{
			temp.at(i) = 1;
		}
		else
		{
			temp.at(i) = 0;
		}
	}
	return temp;
}


int main()
{
	
	string bin;
	int x;
	cout<<"Nhap so nguyen tu 0 - 255 : ";
	cin>>x;
	while(x<0 || x >255)
	{
		cout<<"Gia tri khong hop le, nhap lai gia tri tu 0 - 255 : ";
		cin>>x;
	}

	string temp;
	for(int i=0;i<8;i++)
	{
		if(x-=pow(2,i > 0))
		{
			temp.at(i) = 1;
		}
		else
		{
			temp.at(i) = 0;
		}
	}
	
	
	
	
	
	return 0;
}
