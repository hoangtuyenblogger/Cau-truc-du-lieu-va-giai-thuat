#include<iostream>
using namespace std;

struct node 
{
	int data;
	node *pLeft;
	node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void creatTREE(TREE &tree)
{
	tree = NULL;
}

void push_to_tree(TREE &tree, int x)
{
	if(tree == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		tree = p;
	}
	else
	{
		if(x < tree->data)
		{
			push_to_tree(tree->pLeft,x);
		}
		else
		{
			if(x > tree->data)
			{
				push_to_tree(tree->pRight,x);
			}
		}
	}
}


void pop_from_tree_NLR(TREE tree)
{
	if(tree != NULL)
	{
		
		cout<<tree->data<<" "; // xuat root
		pop_from_tree_NLR(tree->pLeft); // duyet trai
		pop_from_tree_NLR(tree->pRight); // duyet ben phai
	}	
}
void pop_from_tree_LRN(TREE tree)
{
	if(tree != NULL)
	{
		pop_from_tree_LRN(tree->pLeft);
		pop_from_tree_LRN(tree->pRight);
		cout<<tree->data<<" ";	
	}
}



bool kiem_tra_gia_tri_trong_cay(TREE tree, int x)
{
	if(tree!= NULL)
	{
		if(x == tree->data)
		{
			return true;
		}
		else
		{
			if(x > tree->data)
			{
				kiem_tra_gia_tri_trong_cay(tree->pRight,x);
			}
			else
			{
				kiem_tra_gia_tri_trong_cay(tree->pLeft,x);
			}
		}
	}
	else
	{
		return false;
	}
	
}
void them_vao_mang(TREE tree, int arr[], int &n)
{
	if(tree!=NULL)
	{
		arr[n++] = tree->data;
		them_vao_mang(tree->pLeft,arr,n);
		them_vao_mang(tree->pRight,arr,n);
	}
	
}
void tim_cap_so(int arr[], int n, int s)
{
	int kiemtra=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]+arr[j] == s)
			{
				cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
				kiemtra++;
			}
		}
	}
	if(kiemtra==0)
	{
		cout<<"Khong co cap so nao co tong bang "<<s<< " ! "<<endl;
	}
}
bool so_nguyen_to(int a)
{
	if(a<0)
	{
		return false;
	}
	else if(a == 2)
	{
		return true;
	}
	else
	{
		for(int i=2;i<a;i++)
		{
			if(a % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
int main()
{
	TREE cay_nhi_phan;
	creatTREE(cay_nhi_phan);
	//int arr[100];
	//int n=0;
	
	int chucnang;
	do
	{
		cout<<"\n\n\t\t------------------Menu--------------\n";
		cout<<"0. Thoat!\n";
		cout<<"1. Nhap du lieu vao cay nhi phan\n";
		cout<<"2. Duyet cay theo NLR\n";
		cout<<"3. Duyet cay theo LRN \n";
		cout<<"4. Tim va in ra cac cap so co tong bang 1 so cho truoc \n";
		cout<<"5. Xoa so nguyen to \n";
		cout<<"\n\n\t\t------------------Menu--------------\n";
		cout<<"Chon chuc nang : ";
		cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case(1):
			{
				int x;
				cout<<"Nhap gia tri : ";
				cin>>x;
				if(kiem_tra_gia_tri_trong_cay(cay_nhi_phan,x))
				{
					cout<<"Ban da them gia tri nay roi ! \n";
					break;
				}
				else
				{
					//arr[n++] = x;
					push_to_tree(cay_nhi_phan,x);
					system("cls");
					cout<<"Them thanh cong !\n";
				}
				break;
			}
			case(2):
				{
					cout<<"Duyet cay NLR : \n";
					pop_from_tree_NLR(cay_nhi_phan);
					break;
				}
			case(3):
				{
					cout<<"Duyet cay LRN : \n";
					pop_from_tree_LRN(cay_nhi_phan);
					break;
				}
			case(4):
				{
					int arr[100];
					int n=0;
					them_vao_mang(cay_nhi_phan,arr,n);
					int s;
					cout<<"Nhap tong cua cap so : ";
					cin>>s;
					tim_cap_so(arr,n,s);
					break;
				}
			case(5):
				{
					int a;
					cout<<"Nhap so a :";
					cin>>a;
					if(so_nguyen_to(a))
					{
						cout<<a<<" la so nguyen to\n";
					}
				}
		}
	}
	while(chucnang != 0);
	return 0;
}

