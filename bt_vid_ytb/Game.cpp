#include <iostream.h>
#include <string.h>
#include <iomanip.h>
class NhanVat
{
	private:
		int lv; //cap do
		int tt;//thuoc tinh kim-moc-thuy-hoa-tho
	public:
		virtual void nhap()
		{
			cout<<"\tNhap cap do: ";cin>>this->lv;
			cout<<"\tChon thuoc tinh: "<<endl;
			cout<<"\t1.Kim	2.Moc	3.Thuy	4.Hoa	5.Tho: ";cin>>this->tt;
		}
		int get_tt()
		{
			return tt;
		}	
		int get_lv()
		{
			return lv;
		}
		virtual void xuat()
		{
			cout<<setw(20)<<left<<this->lv;
			if(this->tt==1){
				cout<<setw(20)<<left<<"He Kim";
			}else if(this->tt==2){
				cout<<setw(20)<<left<<"He Moc";
			}else if(this->tt==3){
				cout<<setw(20)<<left<<"He Thuy";
			}else if(this->tt==4){
				cout<<setw(20)<<left<<"He Hoa";
			}else{
				cout<<setw(20)<<left<<"He Tho";
			}
		}
		virtual int phan_loai()=0;
		virtual int dame();	
};

class NguoiChoi : public NhanVat
{
	private:
		char ten[50];//ten nhan vat
		int monphai;
	public:
		void nhap()
		{
			NhanVat::nhap();
			fflush(stdin);
			cout<<"\tNhap ten nhan vat: ";cin.getline(this->ten, 50);
			cout<<"\tMon phai: ";
			if(get_tt()==1){
				cout<<"\t1.Thieu Lam	2.Thien Vuong Bang: ";cin>>this->monphai;
			}else if(get_tt()==2){
				cout<<"\t3.Ngu Doc Giao		4.Duong Mon: ";cin>>this->monphai;
			}else if(get_tt()==3){
				cout<<"\t5.Nga My		6.Thuy Yen Mon: ";cin>>this->monphai;
			}else if(get_tt()==4){
				cout<<"\t7.Cai Bang		8.Thien Nhan Giao: ";cin>>this->monphai;
			}else{
				cout<<"\t9. Con Lon		10.Vo Dang: ";cin>>this->monphai;
			}
		}	
		int dame()
		{
			return get_lv()*5;
		}
	
		void xuat()
		{
			NhanVat::xuat();
			cout<<setw(20)<<left<<this->ten;
			if(monphai==1){
				cout<<setw(20)<<left<<"Thieu Lam";
			}else if(monphai==2){
				cout<<setw(20)<<left<<"Thien Vuong Bang";
			}else if(monphai==3){
				cout<<setw(20)<<left<<"Ngu Doc Giao";
			}else if(monphai==4){
				cout<<setw(20)<<left<<"Duong Mon";
			}else if(monphai==5){
				cout<<setw(20)<<left<<"Nga My";      
			}else if(monphai==6){
				cout<<setw(20)<<left<<"Thuy Yen Mon";      
			}else if(monphai==7){
				cout<<setw(20)<<left<<"Cai Bang";      
			}else if(monphai==8){
				cout<<setw(20)<<left<<"Thien Nhan Giao";      
			}else if(monphai==9){
				cout<<setw(20)<<left<<"Con Lon";      
			}else{
				cout<<setw(20)<<left<<"Vo Dang";      
			}
			cout<<setw(20)<<left<<"x";
			cout<<setw(20)<<left<<dame()<<endl;
		}	
		int phan_loai()
		{
			return 1;
		}
		
};
class QuaiVat :public NhanVat
{
	private:
		char quai[15];// loai quai vat
	public:
	void nhap()
		{
			NhanVat::nhap();
			fflush(stdin);
			cout<<"\tNhap loai quai: Thong thuong/ Dau linh? ";cin.getline(this->quai,15);
		}	
		int dame()
		{
			if(strcmpi(this->quai,"thong thuong")==0){
				return get_lv()*3;
			}else{
				return get_lv()*7;
			}
		}
		
		void xuat()
		{
			NhanVat::xuat();
			cout<<setw(20)<<left<<"x";
			cout<<setw(20)<<left<<"x";
			cout<<setw(20)<<left<<this->quai;
			cout<<setw(20)<<left<<dame()<<endl;
		}	
		int phan_loai()
		{
			return 2;
		}	
};
void tieude()
{
	cout<<setw(20)<<left<<"Level ";
	cout<<setw(20)<<left<<"Thuoc tinh";
	cout<<setw(20)<<left<<"Ten nhan vat";
	cout<<setw(20)<<left<<"Mon Phai";
	cout<<setw(20)<<left<<"Loai quai";
	cout<<setw(20)<<left<<"Sat thuong"<<endl;
}								
class QuanLy
{
	NhanVat *a[100];
	int n;
	NhanVat *b[2];
	public:
		void nhap()
		{
			int chon1;
			int i=0;
			while(1)
			{
				cout<<"\n1.Nguoi choi		2.Quai vat		3.Thoat: ";cin>>chon1;
			 	if(chon1==1) a[i]=new NguoiChoi();
				else if(chon1==2) a[i]= new QuaiVat();
				else break;
				a[i]->nhap();
				i++;	
			}
			n=i;
			cout<<endl;
		}	
		void xuat()
		{
			tieude();
			for(int i=0; i<n; i++)
			{
				a[i]->xuat();
			}
		}
		
		int max_sat_thuong()
		{
			int max=a[0]->dame();
			for(int i=0; i<n; i++)
			{
				if(a[i]->dame() > max)
				{
					max=a[i]->dame();
				}
			}
			return max;
		}
		void tim_max_sat_thuong()
		{
			cout<<"\nPhan tu co sat thuong cao nhat: "<<endl;
			tieude();
			for(int i=0; i<n; i++)
			{
				if(a[i]->dame()==max_sat_thuong())
				{
					a[i]->xuat();
				}
			}
		}
		void nhap_A_B()
		{
			int chon;
			cout<<"\nNhap A,B "<<endl;
			for(int i=0; i<2; i++)
			{
				cout<<"\n1.Nguoi choi		2.Quai vat		: ";cin>>chon;
			 	if(chon==1) b[i]=new NguoiChoi();
				else if(chon==2) b[i]=new QuaiVat();
				else break;
				b[i]->nhap();	
			}
			cout<<endl;
		}
		void xuat_A_B()
		{
			tieude();
			for(int i=0; i<2;i++)
			{
				b[i]->xuat();
			}
		}
		void gay_dame()
		{
			double s1,s2;//kim-moc-thuy-hoa-tho ->>Sinh:kim-thuy-moc-hoa-tho-kim
			if(b[0]->get_tt()==1 && b[1]->get_tt()==3
			|| b[0]->get_tt()==2 && b[1]->get_tt()==4
			|| b[0]->get_tt()==3 && b[1]->get_tt()==2
			|| b[0]->get_tt()==4 && b[1]->get_tt()==5
			|| b[0]->get_tt()==5 && b[1]->get_tt()==1)
			{
				s1=b[0]->dame()*1.1;
				s2=b[1]->dame();
			}else if(b[1]->get_tt()==1 && b[0]->get_tt()==3
			|| b[1]->get_tt()==2 && b[0]->get_tt()==4
			|| b[1]->get_tt()==3 && b[0]->get_tt()==2
			|| b[1]->get_tt()==4 && b[0]->get_tt()==5
			|| b[1]->get_tt()==5 && b[0]->get_tt()==1){
				s2=b[1]->dame()*1.1;
				s1=b[0]->dame();
			}
			//-->Khac: kim-moc-tho-thuy-hoa-kim
			else if(b[0]->get_tt()==1 && b[1]->get_tt()==2
			|| b[0]->get_tt()==2 && b[1]->get_tt()==5
			|| b[0]->get_tt()==3 && b[1]->get_tt()==4
			|| b[0]->get_tt()==4 && b[1]->get_tt()==1
			|| b[0]->get_tt()==5 && b[1]->get_tt()==3)
			{
				s1=b[0]->dame()*1.2;
				s2=b[1]->dame()*0.8;
			}else if(b[1]->get_tt()==1 && b[0]->get_tt()==2
			|| b[1]->get_tt()==2 && b[0]->get_tt()==5
			|| b[1]->get_tt()==3 && b[0]->get_tt()==4
			|| b[1]->get_tt()==4 && b[0]->get_tt()==1
			|| b[1]->get_tt()==5 && b[0]->get_tt()==3)
			{
				s1=b[0]->dame()*0.8;
				s2=b[1]->dame()*1.2;
			}
				else{
				s1=b[0]->dame();
				s2=b[1]->dame();
			}
			
			cout<<"Sat thuong A len B = "<<s1<<endl;
			cout<<"Sat thuong B len A = "<<s2<<endl;
			if(s1 > s2 ){
				cout<<"A > B"<<endl;
			}else if(s1 < s2){
				cout<<"A < B"<<endl;
			}else{
				cout<<"A=B"<<endl;
			}
		}
		
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	q.tim_max_sat_thuong();
	q.nhap_A_B();
	q.xuat_A_B();
	q.gay_dame();
	return 0;
}