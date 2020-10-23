#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
typedef struct tagnode
{
    int x;
    struct tagnode *next;
    struct tagnode *pre;
}node;
typedef struct tagsolon
{
    char c;
    node *dau;
    node *cuoi;
}solon;
void xuat(solon n);
void taosolon(solon &n);
node *taonode(int x);
void themdau(solon &n,node *p);
void nhap(solon &n);
void cong(solon n1,solon n2,solon &n);
void tru(solon n1,solon n2,solon &n);
int sosanh(solon n1,solon n2);
void nhan(solon n1,solon n2,solon &n);
void nhan1so(solon n1,int x,solon &n);
void themcuoi(solon &n,node *p);
void xoa(solon &n);
void xoatruocQ(solon &n,node *Q);
void xoacuoi(solon &n);
void chia(solon n1,solon n2,solon &n);
void xuly(solon &n);

int main()
{
    solon n,n1,n2;
    taosolon(n);taosolon(n1);taosolon(n2);
    cout<<"nhap 2 so nguyen:\n";
    cout<<"a=";nhap(n1);
    cout<<"b=";nhap(n2);
    cout<<"\n1.cong."
        <<"\n2.tru."
        <<"\n3.nhan."
        <<"\n4.chia.\n\n";
    int k;
    cin>>k;
    switch(k)
    {
    case 1:cong(n1,n2,n);cout<<"a+b = ";xuat(n);cout<<endl;break;
    case 2:tru(n1,n2,n);cout<<"a-b = ";xuat(n);cout<<endl;break;
    case 3:nhan(n1,n2,n);cout<<"a*b = ";xuat(n);cout<<endl;break;
    case 4:chia(n1,n2,n);break;
    }
    system("pause");
    return 0;
}


void chia(solon n1,solon n2,solon &n)
{
    if(n1.c==n2.c) n.c='+';
    else n.c='-';
    int q=sosanh(n1,n2);
    if(q<0)
    {
        cout<<"ket qua = 0 \ndu ";xuat(n1);
    }
    else if(q==0) cout<<"ket qua = 1";
    else
    {
        int i;
        solon a;taosolon(a);
        solon b;taosolon(b);
        solon c;taosolon(c);
        node *p,*p2,*p1;
        p1=n1.dau;
        p2=n2.dau;
        while(p2!=NULL)
        {
            p=taonode(p1->x);
            themcuoi(a,p);
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=NULL)
        {
            q=sosanh(a,n2);
            if(q<0)
            {
                p=taonode(0);
                themcuoi(n,p);
                p=taonode(p1->x);
                themcuoi(a,p);
            }
            else if(q==0)
            {
                p=taonode(1);
                themcuoi(n,p);
                xoa(a);
                p=taonode(p1->x);
                themcuoi(a,p);
            }
            else
            {
                for(i=1;i<=9;i++)
                {
                    xoa(b);
                    nhan1so(n2,i,b);
                    q=sosanh(a,b);
                    if(q<0)
                    {
                        xoa(b);
                        nhan1so(n2,i-1,b);
                        break;
                    }
                }
                i--;
                p=taonode(i);
                themcuoi(n,p);
                xoa(c);
                tru(a,b,c);
                xoa(a);
                p2=c.dau;
                while(p2!=NULL)
                {
                    p=taonode(p2->x);
                    themcuoi(a,p);
                    p2=p2->next;
                }
                p=taonode(p1->x);
                themcuoi(a,p);
            }
            if(p1!=NULL)p1=p1->next;
        }
        // thuc hien 1 lan nua
        q=sosanh(a,n2);
        if(q<0)
        {
            p=taonode(0);
            themcuoi(n,p);
        }
        else if(q==0)
        {
            p=taonode(1);
            themcuoi(n,p);
        }
        else
        {
            for(i=1;i<=9;i++)
            {
                xoa(b);
                nhan1so(n2,i,b);
                q=sosanh(a,b);
                if(q<0)
                {
                    xoa(b);
                    nhan1so(n2,i-1,b);
                    break;
                }
            }
            i--;
            p=taonode(i);
            themcuoi(n,p);
            xoa(c);
            tru(a,b,c);
            xoa(a);
            p2=c.dau;
            while(p2!=NULL)
            {
                p=taonode(p2->x);
                themcuoi(a,p);
                p2=p2->next;
            }
        }
        if(p1!=NULL)p1=p1->next;
        //end
        xuly(n);xuly(a);
        cout<<"a/b = ";xuat(n);cout<<endl;
        if(a.dau!=NULL)
        {
            cout<<"du ";
            xuat(a);
            cout<<endl;
        }
    }
}
void xoatruocQ(solon &n,node *Q)
{
    if(Q==NULL) xoacuoi(n);
    else
    {
        node *p=Q->pre;
        if(p!=NULL)
        {
            if(p==n.dau)
            {
                n.dau=Q;
                n.dau->pre=NULL;
                delete p;
            }
            else
            {
                p->pre->next=Q;
                Q->pre=p->pre;
                delete p;
            }
        }
    }
}
void xuly(solon &n)
{
    node *p=n.dau;
    while(p!=NULL && p->x==0)
    {
        p=p->next;
        xoatruocQ(n,p);
    }
}
void nhan(solon n1,solon n2,solon &n)
{
    node *p,*p1,*p2;
    long long i,dem=0;
    solon a;taosolon(a);
    solon b;taosolon(b);
    p=n2.cuoi;
    while(p!=NULL)
    {
        xoa(a);
        nhan1so(n1,p->x,a);
        for(i=0;i<dem;i++)
        {
            p1=taonode(0);
            themcuoi(a,p1);
        }
        xoa(b);
        p2=n.cuoi;
        while(p2!=NULL)
        {
            p1=taonode(p2->x);
            themdau(b,p1);
            p2=p2->pre;
        }
        xoa(n);
        cong(a,b,n);
        p=p->pre;
        dem++;
    }
    if(n1.c==n2.c) n.c='+';
    else n.c='-';
    xuly(n);
}
void xoa(solon &n)
{
    while(n.dau!=NULL) xoacuoi(n);
}
void xoacuoi(solon &n)
{
    node *p=n.cuoi;
    if(p!=NULL)
    {
        if(n.dau==n.cuoi)
        {
            n.dau=n.cuoi=NULL;
            delete p;
        }
        else
        {
            n.cuoi=p->pre;
            n.cuoi->next=NULL;
            delete p;
        }
    }
}
void themcuoi(solon &n,node *p)
{
    if(n.dau==NULL)n.dau=n.cuoi=p;
    else
    {
        n.cuoi->next=p;
        p->pre=n.cuoi;
        n.cuoi=p;
    }
}
void nhan1so(solon n1,int x,solon &n)
{
    node *p1,*p;
    int k,m=0;
    p1=n1.cuoi;
    while(p1!=NULL)
    {
        k=p1->x*x+m;
        if(k>=10)
        {
            m=k/10;
            k=k%10;
        }
        else m=0;
        p=taonode(k);
        themdau(n,p);
        p1=p1->pre;
    }
    if(m>0)
    {
        p=taonode(m);
        themdau(n,p);
    }
}
void tru(solon n1,solon n2,solon &n)
{
    int q=sosanh(n1,n2);
    int k,m;
    node *p,*p1,*p2;
    if(q==0) return;
    if(n1.c=='+' && n2.c=='+')
    {
        if(q>0)
        {
            m=0;n.c='+';
            p1=n1.cuoi;p2=n2.cuoi;
            while(p1!=NULL && p2!=NULL)
            {
                if(p1->x < (p2->x + m))
                {
                    k=10+p1->x-p2->x-m;
                    m=1;
                }
                else
                {
                    k=p1->x-p2->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p1=p1->pre;
                p2=p2->pre;
            }
            while(p1!=NULL)
            {
                if(p1->x < m)
                {
                    k=10+p1->x-m;
                    m=1;
                }
                else
                {
                    k=p1->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p1=p1->pre;
            }
        }
        else
        {
            m=0;n.c='-';
            p1=n1.cuoi;p2=n2.cuoi;
            while(p1!=NULL && p2!=NULL)
            {
                if(p2->x < (p1->x + m))
                {
                    k=10+p2->x-p1->x-m;
                    m=1;
                }
                else
                {
                    k=p2->x-p1->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p2=p2->pre;
                p1=p1->pre;
            }
            while(p2!=NULL)
            {
                if(p2->x < m)
                {
                    k=10+p2->x-m;
                    m=1;
                }
                else
                {
                    k=p2->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p2=p2->pre;
            }
        }
    }
    else if(n1.c=='-' && n2.c=='-')
    {
        if(q>0)
        {
            m=0;n.c='-';
            p1=n1.cuoi;p2=n2.cuoi;
            while(p1!=NULL && p2!=NULL)
            {
                if(p1->x < (p2->x + m))
                {
                    k=10+p1->x-p2->x-m;
                    m=1;
                }
                else
                {
                    k=p1->x-p2->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p1=p1->pre;
                p2=p2->pre;
            }
            while(p1!=NULL)
            {
                if(p1->x < m)
                {
                    k=10+p1->x-m;
                    m=1;
                }
                else
                {
                    k=p1->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p1=p1->pre;
            }
        }
        else
        {
            m=0;n.c='+';
            p1=n1.cuoi;p2=n2.cuoi;
            while(p1!=NULL && p2!=NULL)
            {
                if(p2->x < (p1->x + m))
                {
                    k=10+p2->x-p1->x-m;
                    m=1;
                }
                else
                {
                    k=p2->x-p1->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p2=p2->pre;
                p1=p1->pre;
            }
            while(p2!=NULL)
            {
                if(p2->x < m)
                {
                    k=10+p2->x-m;
                    m=1;
                }
                else
                {
                    k=p2->x-m;
                    m=0;
                }
                p=taonode(k);
                themdau(n,p);
                p2=p2->pre;
            }
        }
    }
    else if(n1.c=='+' && n2.c=='-')
    {
        n2.c='+';
        cong(n1,n2,n);
    }
    else if(n1.c=='-' && n2.c=='+')
    {
        n2.c='-';
        cong(n1,n2,n);
    }
    xuly(n);
}
void cong(solon n1,solon n2,solon &n)
{
    if(n1.c==n2.c)
    {
        n.c=n1.c;
        int k,m=0;
        node *p1=n1.cuoi,*p2=n2.cuoi,*p;
        while(p1!=NULL && p2!=NULL)
        {
            k=p1->x+p2->x+m;
            if(k>=10)
            {
                m=k/10;
                k=k%10;
            }
            else m=0;
            p=taonode(k);
            themdau(n,p);
            p1=p1->pre;
            p2=p2->pre;
        }
        while(p1!=NULL)
        {
            k=p1->x+m;
            if(k>=10)
            {
                m=k/10;
                k=k%10;
            }
            else m=0;
            p=taonode(k);
            themdau(n,p);
            p1=p1->pre;
        }
        while(p1!=NULL)
        {
            k=p1->x+m;
            if(k>=10)
            {
                m=k/10;
                k=k%10;
            }
            else m=0;
            p=taonode(k);
            themdau(n,p);
            p1=p1->pre;
        }
        if(m>0)
        {
            p=taonode(m);
            themdau(n,p);
        }

    }
    else if(n1.c=='+' && n2.c=='-')
    {
        n2.c='+';
        tru(n1,n2,n);
    }
    else
    {
        n1.c='+';
        tru(n2,n1,n);
    }
    xuly(n);
}
int sosanh(solon n1,solon n2)
{
    node *p1=n1.cuoi,*p2=n2.cuoi;
    while(p1!=NULL && p2!=NULL)
    {
        p1=p1->pre;
        p2=p2->pre;
    }
    if(p1==NULL && p2!=NULL) return -1;
    if(p1!=NULL && p2==NULL) return 1;
    if(p1==NULL && p2==NULL)
    {
        p1=n1.dau;
        p2=n2.dau;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->x > p2->x) return 1;
            if(p1->x < p2->x) return -1;
            p1=p1->next;
            p2=p2->next;
        }
        return 0;
    }
}
void xuat(solon n)
{
    node *p=n.dau;
    if(p==NULL)
    {
        cout<<0;
        return;
    }
    if(p!=NULL && n.c=='-') cout<<n.c;
    while(p!=NULL)
    {
        cout<<p->x;
        p=p->next;
    }
}
void taosolon(solon &n)
{
    n.c='+';
    n.dau=n.cuoi=NULL;
}
node *taonode(int x)
{
    node *p=new node;
    if(p==NULL) exit(1);
    p->x=x;
    p->next=p->pre=NULL;
    return p;
}
void themdau(solon &n,node *p)
{
    if(n.dau==NULL) n.dau=n.cuoi=p;
    else
    {
        p->next=n.dau;
        n.dau->pre=p;
        n.dau=p;
    }
}
void nhap(solon &n)
{
    string s;
    node *p;
    long long i,j=0;
    getline(cin,s);
    if(s[0]=='-')
    {
        n.c='-';
        j=1;
    }
    else if(s[0]=='+')
    {
        n.c='+';
        j=1;
    }
    else n.c='+';
    for(i=s.size()-1;i>=j;i--)
    {
        switch(s[i])
        {
        case '0':p=taonode(0);break;
        case '1':p=taonode(1);break;
        case '2':p=taonode(2);break;
        case '3':p=taonode(3);break;
        case '4':p=taonode(4);break;
        case '5':p=taonode(5);break;
        case '6':p=taonode(6);break;
        case '7':p=taonode(7);break;
        case '8':p=taonode(8);break;
        case '9':p=taonode(9);break;
        }
        themdau(n,p);
    }
}
