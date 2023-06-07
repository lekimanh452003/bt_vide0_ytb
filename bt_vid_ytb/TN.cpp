#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class SV
{
	private:
		char ma[10];//Ma sinh vien
		char ht[50];// Ho ten
		char k[50];//Dia chi
		int tc;//Tong so tin chi
		float dtb;//Diem trung binh
	public:
		SV(char *ma="", char* ht="", char* k="", int tc=0, float dtb=0)
		{
			strcpy(this->ma,ma);
			strcpy(this->ht,ht);
			strcpy(this->k,k);
			this->tc=tc;
			this->dtb=dtb;
		}	
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\tNhap ma sinh vien: ";cin.getline(this->ma,10);
			cout<<"\tNhap ho ten sinh vien: ";cin.getline(this->ht,50);
			cout<<"\tNhap dia chi: ";cin.getline(this->k,50);
			cout<<"\tNhap tong so tin chi: ";cin>>this->tc;
			cout<<"\tNhap diem trung binh: ";cin>>this->dtb;
		}
		virtual void xuat()
		{
			cout<<setw(15)<<left<<this->ma;
			cout<<setw(15)<<left<<this->ht;
			cout<<setw(15)<<left<<this->k;
			cout<<setw(15)<<left<<this->tc;
			cout<<setw(15)<<left<<this->dtb;
		}
		int get_tc()
		{
			return tc;	
		}
		int get_dtb()
		{
			return dtb;	
		}
		virtual int phan_loai()=0;
		virtual int xet_tot_nghiep(){};
};
void tieude()
{
	cout<<setw(15)<<left<<"Ma";
	cout<<setw(15)<<left<<"Ho ten";
	cout<<setw(15)<<left<<"Dia chi";
	cout<<setw(15)<<left<<"Tin chi";
	cout<<setw(15)<<left<<"DTB";
	cout<<setw(15)<<left<<"Diem TN";
	cout<<setw(15)<<left<<"Ten luan van";
	cout<<setw(15)<<left<<"Diem luan van"<<endl;
}
class CaoDang:public SV
{
	private:
		float dtn;//Diem thi tot nghiep
	public:
		void nhap()
		{
			SV::nhap();
			cout<<"\tNhap diem thi tot nghiep: ";cin>>this->dtn;
		}
	 	
		int phan_loai()
		{
			return 1;
		}
		int xet_tot_nghiep()
		{
			if(get_tc() >= 120 && get_dtb() >=5 && dtn >=5){
				return true;
			}else{
				return false;
			}
		}
		void xuat()
		{
			SV::xuat();
			cout<<setw(15)<<left<<this->dtn<<endl;
		}
};
class DaiHoc :public SV
{
	private:
 		char tlv[50];//Ten luan van
		float dlv;//Diem luan van
	public:
		void nhap()
		{
			SV::nhap();
			fflush(stdin);
			cout<<"\tNhap ten luan van: ";cin.getline(this->tlv, 50);
			cout<<"\tNhap diem thi luan van: ";cin>>this->dlv;
		}
	 	
		int phan_loai()
		{
			return 2;
		}
		int xet_tot_nghiep()
		{
			if(get_tc() >= 170 && get_dtb() >=5 && dlv >=5){
				return true;
			}else{
				return false;
			}
		}
		void xuat()
		{
			SV::xuat();
			cout<<setw(15)<<left<<"x";
			cout<<setw(15)<<left<<this->tlv;
			cout<<setw(15)<<left<<this->dlv<<endl;
		}
};

class Quanly
{
	SV *a[100];
	int n;
	public:
		void nhap()
		{
			int i=0;
			int chon;
			while(1)
			{
				cout<<"\nNhap thong tin sinh vien."<<endl;
				cout<<"\n1.SV Cao dang, 2. SV Dai hoc, 3. Thoat: ";cin>>chon;
				if(chon==1) a[i]=new CaoDang();
				else if(chon==2) a[i]=new DaiHoc();
				else break;
				a[i]->nhap();
				i++;
			}
			n=i;
			cout<<"\nSo luong sinh vien vua nhap = "<<n<<endl;
		}
		
		void xuat()
		{
			tieude();
			for(int i=0; i<n; i++)
			{
				a[i]->xuat();
			}
		}
		void sl_tn()
		{
			int d=0;
			for(int i=0;i<n; i++)
			{
				if(a[i]->xet_tot_nghiep()==true){
					d++;
				}
			}
			cout<<"\nSo luong sinh vien do tot nghiep = "<<d<<endl;
		}
		float max_dtb()
		{
			int max=a[0]->get_dtb();
			for(int i=0; i<n; i++)
			{	
				if(a[i]->get_dtb() >max)
				{
					max=a[i]->get_dtb();		
				}
			}
		return max;
		}
		float tim_max()
		{
			tieude();
			for(int i=0; i<n; i++)
			{
				if(a[i]->get_dtb()==max_dtb())
				{
					a[i]->xuat();
				}
			}
		}
		
};
int main()
{
	Quanly q;
	q.nhap();
	q.xuat();
	q.sl_tn();
	cout<<"\nSinh vien co DTB cao nhat la: "<<endl;
	q.tim_max();
	return 0;
}