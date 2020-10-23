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
TREE node_trai_nhat(TREE tree)
{
	if(tree->pLeft != NULL) // neu chua bang null thi tim ben trai
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
				themang = themang->pRight;
			}
			delete temp;
		}
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
		cout<<"3. Xoa gia tri trong cay nhi phan\n";
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
					int c;
					cout<<"Nhap gia tri can xoa : ";
					cin>>c;
					if(kiem_tra_gia_tri_trong_cay(cay_nhi_phan,c)) // neu trong cay co gia tri can xoa thi xoa
					{
						xoa_gia_tri_trong_cay(cay_nhi_phan,c);
						cout<<"Xoa thanh cong !\n";
					}
					else
					{
						cout<<"Khong xoa duoc ! \n";
					}
					break;
				}
		}
	}
	while(chucnang != 0);
	return 0;
}

