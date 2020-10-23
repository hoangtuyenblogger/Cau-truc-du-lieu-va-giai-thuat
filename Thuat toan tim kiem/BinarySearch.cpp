#include<iostream>
using namespace std;

int binarysearch(int arr[], int n, int k);

int main()
{
	int arr[100];
	int n;
	int k;
	cout << "Nhap so phan tu = ";
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	cout << "Nhap so k can tim : ";
	cin >> k;
	cout << "Vi tri cua " << k << " trong mang la : "<<binarysearch(arr, n, k) << endl;
	system("pause");
	return 0;
}


int binarysearch(int arr[], int n, int k)
{
	int l = 0, r = n - 1, m;
	do
	{
		m = (l + r) / 2;
		if (arr[m] == k) return m;
		else
		{
			if (k > arr[m])
				l = m + 1;
			else
				r = m - 1;
		}
	} while (l < r);
	
	return -1;
}