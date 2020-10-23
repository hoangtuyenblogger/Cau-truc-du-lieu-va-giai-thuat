#include<iostream>
using namespace std;
#include<fstream>

int main()
{
	int a;
	fstream f;
	f.open("input.txt",ios::in);
	while(!f.eof())
	{
		f >> a;
		f.ignore();
	}
	f.close();
	return 0;
}
