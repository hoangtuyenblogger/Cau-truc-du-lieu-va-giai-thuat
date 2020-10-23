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


void pop_from_tree_LNR(TREE tree)
{
	if(tree != NULL)
	{
		pop_from_tree_LNR(tree->pLeft); // duyet trai
		cout<<tree->data<<" "; // xuat root
		pop_from_tree_LNR(tree->pRight); // duyet ben phai
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
void chen_vao_cay_nhi_phan(TREE &tree, int x)
{
	if(x == tree->data)
	{
		return;
	}
	else
	{
		if(x > tree->data)
		{
			TREE temp = tree->pRight;
			tree->data = x;
			chen_vao_cay_nhi_phan(tree->pRight,temp->data);
		}
		if(x < tree->data)
		{
			chen_vao_cay_nhi_phan(tree->pLeft,x);
		}
	}
}

void xuat_vao_mang(TREE tree, int arr[], int &i)
{
	if(tree != NULL)
	{
		xuat_vao_mang(tree->pLeft,arr,i);
		arr[i++] = tree->data;
		xuat_vao_mang(tree->pRight,arr,i);			
	}
}
void xuat_la_cay(TREE tree)
{
	if(tree != NULL)
	{
		if(tree->pLeft == NULL && tree->pRight == NULL)
		{
			cout<<tree->data<<" ";
		}
		xuat_la_cay(tree->pLeft);
		xuat_la_cay(tree->pRight);
	}
}
int main()
{
	TREE cay_nhi_phan;
	creatTREE(cay_nhi_phan);
	
	int chucnang;
	do
	{
		cout<<"\n\n\t\t------------------Menu--------------\n";
		cout<<"0. Thoat!\n";
		cout<<"1. Nhap du lieu vao cay nhi phan\n";
		cout<<"2. Duyet cay theo LNR (gia tri tang dan)\n";
		cout<<"3. Xuat gia tri tang dan vao mang\n";
		cout<<"4. In ra cac la cay\n";
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
					push_to_tree(cay_nhi_phan,x);
					system("cls");
					cout<<"Them thanh cong !\n";
				}
				break;
			}
			case(2):
				{
					cout<<"Duyet cay theo gia tri tang dan : \n";
					pop_from_tree_LNR(cay_nhi_phan);
					break;
				}

			case(3):
				{
					int i=0;
					int arr[100];
					xuat_vao_mang(cay_nhi_phan,arr,i);
					cout<<"Gia tri trong mang la: \n";
					for(int j=0;j<i;j++)
					{
						cout<<arr[j]<<" ";
					}
					break;
				}
			case(4):
				{
					
					cout<<"Cac la cay la : ";
					xuat_la_cay(cay_nhi_phan);
					break;
				}
		}
	}
	while(chucnang != 0);
	return 0;
}

