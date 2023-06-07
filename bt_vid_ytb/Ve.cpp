#include <iostream.h>
#include <string.h>
#include <iomanip.h>
class Ve
{
	private:
		char ma[10];//Ma ve
		char ht[30];//Ho ten nguoi choi
		int ns;//Nam sinh
	
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma ve: ";cin.getline(this->ma, 10);
			cout<<"\tNhap ho ten: ";cin.getline(this->ht, 30);
			cout<<"\tNhap nam sinh: ";cin>>this->ns;
		}
		virtual void xuat()
		{
			cout<<setw(15)<<left<<this->ma;
			cout<<setw(15)<<left<<this->ht;
			cout<<setw(15)<<left<<this->ns;
		}
		virtual long double	tien();
		virtual int phan_loai()=0;
};
class TronGoi : public Ve
{
	public:
		void nhap()
		{
			Ve::nhap();
		}
		long double tien()
		{
			return 200000;
		}
		void xuat()
		{
			Ve::xuat();
			cout<<setw(20)<<left<<"30";
			cout<<setw(20)<<left<<tien()<<endl;
		}
		int phan_loai()
		{
			return 1;
		}
		
			
};
class TungPhan :public Ve
{
	private:
		int sl;//So tro choi ma nguoi choi tham du
	public:
		void nhap()
		{
			Ve::nhap();
			cout<<"\tNhap so luong tro choi: ";cin>>this->sl;
		}
		long double tien()
		{
			return 70000+sl*20000;
		}
		void xuat()
		{
			Ve::xuat();
			cout<<setw(20)<<left<<this->sl;
			cout<<setw(20)<<left<<tien()<<endl;
		}	
		int phan_loai()
		{
			return 2;
		}
};
void tieude()
{
	cout<<setw(15)<<left<<"Ma";
	cout<<setw(15)<<left<<"Ho Ten";
	cout<<setw(15)<<left<<"Nam sinh";
	cout<<setw(20)<<left<<"So luong tro choi";
	cout<<setw(20)<<left<<"Thanh tien"<<endl;
}
class QuanLy
{
	Ve *a[100];
	int n;
	public:
		void nhap()
		{
			int i=0, chon;
			cout<<"\nNhap danh sach cac ve."<<endl;
			while(1)
			{
				cout<<"\n1.Ve tron goi, 2. Ve tung phan, 3. Thoat: ";cin>>chon;
				if(chon==1) a[i]=new TronGoi();
				else if(chon==2) a[i]=new TungPhan();
				else break;
				a[i]->nhap();
				i++;	
			}
			n=i;
		}
		void xuat()
		{
			tieude();
			for(int i=0; i<n; i++)
			{
				a[i]->xuat();
			}
			long double s=0;
			for(int i=0; i<n; i++)
			{
				s=s+a[i]->tien();
			}
			cout<<"\nTong tien ve = "<<s<<endl;
		}	
		void sl_ve_tung_phan()
		{
			int d=0;
			for(int i=0; i<n; i++)
			{
				if(a[i]->phan_loai()==2)
				{
					d++;
				}
			}
			cout<<"\nSo luong ve tung phan = "<<d<<endl;
		}
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	q.sl_ve_tung_phan();
	return 0;
}