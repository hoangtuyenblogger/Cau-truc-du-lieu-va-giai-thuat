#include <iostream>
using namespace std;
#define max 20

void in(int arr[], int& n);
void out(int arr[], int n);
void RadixSort(int a[], int n);

int main()
{
	int n;
	int arr[max];
	in(arr, n);
	RadixSort(arr, n);
	out(arr, n);
	system("pause");
	return 0;
}



void in(int arr[], int& n)
{
	cout << "Nhap so luong phan tu trong mang : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
}
void out(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
// sap xep theo Radix Sort
void RadixSort(int arr[], int n)
{
	int i, b[max];
	int donvi = 1; // donvi = 1 hang don vi, donvi = 10 la hang chuc, donvi = 100 la hang tram , v  . v. . 
	int m = arr[0];
	// tim phan tu co gia tri lon nhat de thuc hien so lan lap lai
	for (i = 0; i < n; i++)
	{
		if (arr[i] > m)
			m = arr[i];
	}
	while (m / donvi > 0)
	{
		// dem so chu so giong nhau
		switch(donvi)
		{
			case(1):
				cout<<"Sap xep theo hang don vi"<<endl;break;
			case(10):
				cout<<"Sap xep theo hang chuc"<<endl;break;
			case(100):
				cout<<"Sap xep theo hang tram"<<endl;break;
			case(1000):
				cout<<"Sap xep theo hang nghin"<<endl;break;
			case(10000):
				cout<<"Sap xep theo hang chuc nghin"<<endl;break;
		}
		int O_nho[10] = { 0 };
		for (i = 0; i < n; i++)
		{
			O_nho[arr[i] / donvi % 10]++;
			cout << "O_nho[" << arr[i] / donvi % 10 << "] = " << O_nho[arr[i] / donvi % 10] << endl;
		}
		cout << endl;
		// danh so thu tu de chua cac gia tri
		cout << "O_nho[" << 0 << "] = " << O_nho[0] << endl;
		for (i = 1; i < 10; i++)
		{
			O_nho[i] += O_nho[i - 1];
			cout << "O_nho[" << i << "] = " << O_nho[i] << endl;
		}
		cout << endl;
		// chuyen cac phan tu trang mang a vao mang b, tu tren xuong duoi
		for (i = n - 1; i >= 0; i--)
		{
			b[--O_nho[arr[i] / donvi % 10]] = arr[i];
			cout << "b[" << O_nho[arr[i] / donvi % 10] << "] = " << arr[i];
			cout << endl;
		}
		// chuyen cac phan tu b vao mang a
		for (i = 0; i < n; i++)
		{
			arr[i] = b[i];
			cout << arr[i] << " ";
		}
		cout << " \n--------------------------------------------------" << endl;
		donvi *= 10; // tang len 1 don vi 
	}


}


