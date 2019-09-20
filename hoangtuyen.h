/*------------------------ class phân số: cộng, trừ, nhân, chia 2 phân số ------------------------- */
class phanso
{
	private: 
		int ucln(int a, int b);
		int tuso;
	 	int mauso;
	 public:
     phanso();
     ~phanso();
     phanso(int &tu,int &mau);
	 void nhap();
     void toigian();
	 void xuat();
	 phanso cong(phanso &b);
	 phanso operator+(phanso &b);
     phanso operator-(phanso &b);
	 phanso operator*(phanso &b);
     phanso operator/(phanso &b);
     float thapphan();
	 
};

/*------------------------ class 1 điểm nào đó I(x,y), M(x,y) -> tính khoảng cách------------------------ */
class diem
{
	private: int x, y;
	public: 
		diem();
		diem(int _x,int _y);
		diem(diem &b);
		~diem();
		void nhap();
		void xuat();
		double kc(diem &M);
};

/*------------------------ Class đường tròn: tính diện tích, chu vi------------------------ */
class duongtron
{
	private: 
		float r;
		float pi;
	public:
		duongtron();
		duongtron(float &bankinh);
		duongtron(duongtron &d);
		~duongtron();
		void nhap();
		void xuat();
		float c();
		float c(float&bankinh);
		float cHT(diem &i, diem &m);
		float s();
		float sHT(diem &i, diem &m);
		float s(float&bankinh);
};

/*------------------------ Kiếm tra số nguyên tố, số hoàn hảo, số chính phương-------------------*/
bool snt(int a);
bool sht(int a);
bool scp(int a);
