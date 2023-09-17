#include <iostream.h>
#include <string.h>
void mau()
{
	cout<<"1.Red			2.Orange		3.Yellow		4.Spring Green"<<endl;
	cout<<"5.Green			6.Turquoise		7.Cyan			8.Ocean"<<endl;
	cout<<"9.Blue			10.Violet		11.Magenta		12.Raspberry"<<endl;
}
class ThanhPhan
{
	private:
		int x, y, d, r;//Toa do (x,y) va chieu dai, chieu rong
		int mchu,mnen;// Mau chu, Mau nen
	public:
		virtual void nhap()
		{
			cout<<"\nNhap toa do: ";cin>>x>>y;
			cout<<"\nNhap chieu dai, chieu rong: ";cin>>d>>r;
		}
		virtual void xuat()
		{
			cout<<"Toa do: ("<<x<<","<<y<<")";
			cout<<"		Chieu dai: "<<d;
			cout<<"		chieu rong: "<<r<<endl;
		}
	 	virtual void chon_mau()
		{
			cout<<"\nNhap mau chu: "<<endl;
			mau();
			cin>>mchu;
			cout<<"\nNhap mau nen: "<<endl;
			mau();
			cin>>mnen;
		}
		virtual void xuat_mau_nen()
		{
			if( mnen==1) cout<<"Red"<<endl;
			else if(mnen==2) cout<<"Orange"<<endl;
			else if(mnen==3) cout<<"Yellow"<<endl;
			else if(mnen==4) cout<<"Spring Green"<<endl;
			else if(mnen==5) cout<<"Green"<<endl;
			else if(mnen==6) cout<<"Turquoise"<<endl;
			else if(mnen==7) cout<<"cyan"<<endl;
			else if(mnen==8) cout<<"Ocean"<<endl;
			else if(mnen==9) cout<<"Blue"<<endl;
			else if(mnen==10) cout<<"Violet"<<endl;
			else if(mnen==11) cout<<"Magenta"<<endl;
			else cout<<"Raspberry"<<endl;
		}
		virtual void xuat_mau_chu()
		{
			if(mchu==1) cout<<"Red"<<endl;
			else if(mchu==2) cout<<"Orange"<<endl;
			else if(mchu==3) cout<<"Yellow"<<endl;
			else if(mchu==4) cout<<"Spring Green"<<endl;
			else if(mchu==5) cout<<"Green"<<endl;
			else if(mchu==6) cout<<"Turquoise"<<endl;
			else if(mchu==7) cout<<"cyan"<<endl;
			else if(mchu==8) cout<<"Ocean"<<endl;
			else if(mchu==9) cout<<"Blue"<<endl;
			else if(mchu==10) cout<<"Violet"<<endl;
			else if(mchu==11) cout<<"Magenta"<<endl;
			else cout<<"Raspberry"<<endl;
		}
		int get_mau_chu()
		{
			return mchu;
		}
		int get_mau_nen()
		{
			return mnen;
		}
		virtual int phan_loai()=0;
};
class Label:public ThanhPhan
{
	private:
		char nd[50];//Noi dung text hien thi
	public:
		void nhap()
		{
			ThanhPhan::nhap();
			fflush(stdin);
			cout<<"\nNhap noi dung text hien thi: ";cin.getline(nd,50);
			cout<<"Chon mau : ";
			do{
				ThanhPhan::chon_mau();	
			}while(get_mau_chu() <= 0 || get_mau_chu() > 12 || get_mau_nen() <= 0 || get_mau_nen() > 12);
		}
		void xuat()
		{
			cout<<"\nLABEL: ";
			ThanhPhan::xuat();
			cout<<"Noi dung Text: "<<this->nd<<endl;
			cout<<"Mau chu: ";
			ThanhPhan::xuat_mau_chu();
			cout<<"Mau nen: ";
			ThanhPhan::xuat_mau_nen();
			
		}
		int phan_loai()
		{
			return 1;
		}
};
class Button: public ThanhPhan
{
	private:
		char nd1[50];//text
		char anh[50];//hinh anh
	public:
		void nhap()
		{
			ThanhPhan::nhap();
			fflush(stdin);
			cout<<"\nNhap noi dung text hien thi /link anh: ";cin.getline(nd1,50);
			cout<<"Chon mau: ";
			do{
				ThanhPhan::chon_mau();	
			}while(get_mau_chu() <= 0 || get_mau_chu() > 12 || get_mau_nen() <= 0 || get_mau_nen() > 12);
		}
		void xuat()
		{
			cout<<"\nBUTTON"<<endl;
			ThanhPhan::xuat();
			cout<<"Noi dung Text: "<<this->nd1<<endl;
			cout<<"Mau chu: ";
			ThanhPhan::xuat_mau_chu();
			cout<<"Mau nen: ";
			ThanhPhan::xuat_mau_nen();
		}
		int phan_loai()
		{
			return 2;
		}
};
class QuanLy
{
	int n;
	ThanhPhan *a[100];
	public:
		void nhap()
		{
			int chon;
			int i=0;
			cout<<"\nNhap danh sach so luong cac thanh phan: ";cin>>n;
			while(i<n)
			{
				cout<<"\n1.Label		2. Button: ";cin>>chon;
				if(chon==1) a[i] = new Label();
				else if(chon==2) a[i] = new Button();
				else break;
				a[i]->nhap();
				i++;
			}
			n=i;
		}
		void xuat()
		{
			for(int i=0; i<n; i++)
			{
				cout<<"\nSTT "<<i+1<<endl;
				a[i]->xuat();
			}
		}
		void kt_tp_dau()
		{
			int s=0;
			if(a[0]->get_mau_chu() > a[0]->get_mau_nen()){
				s=a[0]->get_mau_chu() - a[0]->get_mau_nen();
			}else{
				s=a[0]->get_mau_nen() - a[0]->get_mau_chu();	
			}
			if(s==6)
			{
				cout<<"\nThanh phan dau phoi mau bo tuc truc tiep."<<endl;
			}else{
				cout<<"\nThanh phan dau khong  phai phoi mau bo tuc truc tiep."<<endl;
			}
		}	
		int phoi_mau_don_sac()
		{
			int d=0;
			int s1=a[0]->get_mau_nen();
			for(int i=0; i<n; i++)
			{
				if(a[i]->get_mau_nen() == s1)
				{
					d++;
				}else{
					return false;
				}
			}
			if(d==n)
			{
				cout<<"\nMau nen cac thanh phan phoi mau don sac."<<endl;
			}
		}
		int phoi_mau_bo_tuc()
		{
			int s2=0;
			for(int i=0; i<n-1 ;i++)
			{
				for(int j=i+1; j<n; j++)
				{
					if(a[i]->get_mau_nen() > a[j]->get_mau_nen())
					{
						s2=a[i]->get_mau_nen() - a[j]->get_mau_nen();
					}else if(a[i]->get_mau_nen() < a[j]->get_mau_nen())
					{
						s2=a[j]->get_mau_nen() - a[i]->get_mau_nen();
					}
					else{
						return false;
					}
				}	
			}
			if(s2==6)
			{
				cout<<"\nMau nen cac thanh phan phoi mau bo tuc truc tiep."<<endl;
			}
		}
		bool phoi_mau_tuong_dong()
		{
			int s3=0;
			for(int i=1; i<n-1; i++)
			{
				if(a[i]->get_mau_nen() > a[i-1]->get_mau_nen() 
				&& a[i]->get_mau_nen() < a[i+1]->get_mau_nen())
				{
					s3=a[i+1]->get_mau_nen() - a[i-1]->get_mau_nen();	
				}
				else if(a[i]->get_mau_nen() < a[i-1]->get_mau_nen() 
				&& a[i]->get_mau_nen() > a[i+1]->get_mau_nen())
				{
					s3=a[i-1]->get_mau_nen() - a[i+1]->get_mau_nen();
				}
				else
				{
					return false;
				}
			}
			if(s3==2){
				cout<<"\nPhoi mau tuong dong."<<endl;
			}
		}
		int check()
		{
			if(phoi_mau_don_sac()==false )
			{
				if(phoi_mau_bo_tuc()==false)
				{
					if(phoi_mau_tuong_dong()==false)
					{
						cout<<"\nKhong phu hop voi quy tac phoi mau nao."<<endl;
					}
				}
			}
		}
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	q.kt_tp_dau();
	q.phoi_mau_don_sac();
	q.phoi_mau_bo_tuc();
	q.phoi_mau_tuong_dong();
	q.check();
	return 0;  
} 