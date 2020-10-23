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
	else if(x > tree->data)
	{
		push_to_tree(tree->pRight,x);
	}
	else if(x < tree->data)
	{
		push_to_tree(tree->pLeft,x);
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
TREE node_trai_nhat(TREE tree)
{
	if(tree->pLeft!= NULL)
	{
		node_trai_nhat(tree->pLeft);
	}
	else // tree->pLeft == NULL
	{
		return tree;
	}
}
void xoa_gia_tri_trong_cay(TREE &tree, int x)
{
	if(tree == NULL)
	{
		return;
	}
	else
	{
		if(x > tree->data)
		{
			xoa_gia_tri_trong_cay(tree->pRight,x);
		}
		else if(x < tree->data)
		{
			xoa_gia_tri_trong_cay(tree->pLeft,x);
		}
		else // x = tree->data
		{
			TREE temp = tree; // temp la node the mang, temp se bi xoa
			if(tree->pLeft == NULL) // co cay con phai
			{
				tree = tree->pRight;
			}
			else if(tree->pRight == NULL) // co cay con trai
			{
				tree = tree->pLeft;
			}
			else // co day con trai va co cay con phai
			{
				TREE themang = node_trai_nhat(tree->pRight);
				temp->data = themang->data;
				temp = themang;
				themang = NULL;
			}
			delete temp;
		}
	}
}
bool kiem_tra_so_chan(int a)
{
	if(a % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int dem_so_chan(TREE tree)
{
	if(tree != NULL)
	{
		int a = dem_so_chan(tree->pLeft);
		int b = dem_so_chan(tree->pRight);
		if(tree->data % 2 == 0)
		{
			return 1 + a + b;
		}
		else
		{
			return a + b;
		}
	}
	return 0;
}
void them_so_chan_vao_mang(TREE tree, int arr[], int &n)
{
	if(tree == NULL)
	{
		return;
	}
	else
	{
		if(tree->data % 2 == 0)
		{
			arr[n++] = tree->data;
		}
		them_so_chan_vao_mang(tree->pLeft,arr,n);
		them_so_chan_vao_mang(tree->pRight,arr,n);
	}
}
void xoa_so_chan(TREE &tree)
{
	if(tree!= NULL)
	{
		xoa_so_chan(tree->pLeft);
		xoa_so_chan(tree->pRight);
		if(kiem_tra_so_chan(tree->data) == true)
		{
			xoa_gia_tri_trong_cay(tree,tree->data);
		}
		
	}
}
int Max_cay_nhi_phan(TREE tree)
{
	if(tree != NULL)
	{
		
		if(tree->pRight != NULL)
		{
			return Max_cay_nhi_phan(tree->pRight);
		}
		return tree->data;
	}
}

int main()
{
	TREE cay_nhi_phan;
	creatTREE(cay_nhi_phan);
	int arr[100];
	int i=0;
	
	int chucnang;
	do
	{
		cout<<"\n\n\t\t------------------Menu--------------\n";
		cout<<"0. Thoat!\n";
		cout<<"1. Nhap du lieu vao cay nhi phan\n";
		cout<<"2. Duyet cay theo LNR (gia tri tang dan)\n";
		cout<<"3. Dem va xoa so chan bang mang\n";
		cout<<"4. Xoa va dem so chan bang de qui \n";
		cout<<"5. Tim gia tri lon nhat trong cay nhi phan\n";
		cout<<"6. Xoa gia tri trong cay nhi phan\n";
		cout<<"7. Tim gia tri nho nhat trong cay\n";
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
					if(x % 2 == 0)
					{
						arr[i++] = x;
					}
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
					int arr[100];
					int n=0;
					them_so_chan_vao_mang(cay_nhi_phan,arr,n);
					for(int i=0;i<n;i++)
					{
						xoa_gia_tri_trong_cay(cay_nhi_phan,arr[i]);
					}
					break;
				}
			case(4):
				{
					cout<<"Co "<<dem_so_chan(cay_nhi_phan)<<"  so chan trong cay nhi phan\n";
					xoa_so_chan(cay_nhi_phan);
					
					break;
				}
			case(5):
				{
					cout<<"Gia tri lon nhat trong cay nhi phan la : "<<Max_cay_nhi_phan(cay_nhi_phan)<<endl;
					break;
				}
			case(6):
				{
					int a;
					cout<<"Nhap gia tri can xoa : ";
					cin>>a;
					xoa_gia_tri_trong_cay(cay_nhi_phan,a);
					cout<<"Da xoa !\n";
					break;
				}
			case(7):
				{
					NODE *temp = node_trai_nhat(cay_nhi_phan);
					cout<<"Gia tri nho nhat trong cay la : "<<temp->data<<endl;
					break;
				}
		}
	}
	while(chucnang != 0);
	return 0;
}

