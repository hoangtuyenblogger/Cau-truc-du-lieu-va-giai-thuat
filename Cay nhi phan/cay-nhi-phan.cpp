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
		pop_from_tree_NLR(tree->pLeft); // xuat trai
		pop_from_tree_NLR(tree->pRight); // xuat phai
	}	
}

void pop_from_tree_NRL(TREE tree)
{
	if(tree != NULL)
	{
		cout<<tree->data<<" "; // xuat root
		pop_from_tree_NRL(tree->pRight); // xuat phai
		pop_from_tree_NRL(tree->pLeft); // xuat trai
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
void pop_from_tree_RNL(TREE tree)
{
	if(tree != NULL)
	{
		pop_from_tree_RNL(tree->pRight); // duyet trai
		cout<<tree->data<<" "; // xuat root
		pop_from_tree_RNL(tree->pLeft); // duyet ben phai
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
bool kiem_tra_so_nguyen_to(int x)
{
	if(x<2)
	{
		return false;
	}
	if(x == 2)
	{
		return true;
	}
	for(int i = 2; i<x;i++)
	{
		if(x % i == 0)
		{
			return false;
		}
	}
	return true;
}

void Dem_sl_so_nguyen_to(TREE tree, int &count)
{
	if( tree != NULL)
	{
		if(kiem_tra_so_nguyen_to(tree->data) == true)
		{
			count++;
		}
		Dem_sl_so_nguyen_to(tree->pLeft,count);
		Dem_sl_so_nguyen_to(tree->pRight,count);
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

TREE node_trai_nhat(TREE tree)
{
	if(tree->pLeft != NULL) // neu chua bang null thi tim ben trai
	{
		node_trai_nhat(tree->pLeft);
	}
	else // tree->pLeft == NULL
	{
		return tree->pLeft;
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
		if(x > tree->data) // xoa phai
		{
			xoa_gia_tri_trong_cay(tree->pRight,x);
		}
		else if(x < tree->data) // xoa trai
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
	if(a%2 == 0)
	{
		return true;
	}
	else{
		return false;
	}
}

void dem_so_chan(TREE tree, int &a)
{
	if(tree != NULL)
	{
		if(kiem_tra_so_chan(tree->data))
		{
			a++;
		}
		dem_so_chan(tree->pLeft,a);
		dem_so_chan(tree->pRight,a);
	}
	
}
void xoa_so_chan(TREE &tree)
{
	if(tree != NULL)
	{
		if(tree->data % 2 == 0)
		{
			xoa_gia_tri_trong_cay(tree,tree->data);
		}
	}
	xoa_so_chan(tree->pLeft);
		xoa_so_chan(tree->pRight);
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
		cout<<"2. Duyet cay theo NLR\n";
		cout<<"3. Duyet cay theo NRL\n";
		cout<<"4. Duyet cay theo LNR (gia tri tang dan)\n";
		cout<<"5. Duyet cay theo RNL (Gia tri giam dan)\n";
		cout<<"6. Duyet cay theo LRN\n";
		cout<<"7. Dem so luong so nguyen to trong cay nhi phan\n";
		cout<<"8. Tim kiem gia tri trong cay nhi phan\n";
		cout<<"9. Dem so chan trong cay va xoa so chan \n";
		cout<<"10. Xoa gia tri trong cay nhi phan\n";
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
				cout<<"Duyet cay theo NLR : \n";
				pop_from_tree_NLR(cay_nhi_phan);
				cout<<endl;
				break;
			}
			case(3):
				{
					cout<<"Duyet cay theo NLR : \n";
					pop_from_tree_NRL(cay_nhi_phan);
					break;
				}
			case(4):
				{
					cout<<"Duyet cay theo LNR (gia tri tang dan) : \n";
					pop_from_tree_LNR(cay_nhi_phan);
					break;
				}
			case(5):
				{
					cout<<"Duyet cay theo LNR (gia tri giam dan) : \n";
					pop_from_tree_RNL(cay_nhi_phan);
					break;
				}
			case(6):
				{
					cout<<"Duyet cay theo LRN : \n";
					pop_from_tree_LRN(cay_nhi_phan);
					break;
				}
			case(7):
				{
					int count = 0;
					Dem_sl_so_nguyen_to(cay_nhi_phan,count);
					cout<<"Co "<<count<<" so nguyen to trong cay nhi phan \n";
					break;
				}
			case(8):
				{
					int a;
					cout<<"Nhap gia tri can tim : \n";
					cin>>a;
					if(kiem_tra_gia_tri_trong_cay(cay_nhi_phan,a))
					{
						cout<<"Co gia tri "<<a<<" trong cay nhi phan\n";
					}
					else{
						cout<<"Khong tim thay gia tri !\n";
					}
					break;
				}
			case(9):
				{
					int count=0;
					int arr[100];
					int n=0;
					dem_so_chan(cay_nhi_phan,count);
					cout<<"Trong cay nhi phan co "<<count<<" so chan !"<<endl;
					
					xoa_so_chan(cay_nhi_phan);
					
					break;
				}
			case(10):
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

