#include<iostream>
#include<string.h>
using namespace std;

int main()
{

	string name;
	cout<<"Nhap ten : ";
	getline(cin,name);
	for(int i=0;i<name.length();i++)
	{
		if(stricmp(&name[i],'t') == 0)
		{
			cout<<name[i]<< " ";
		}
	}
	system("pause");
	
	return 0;
}
