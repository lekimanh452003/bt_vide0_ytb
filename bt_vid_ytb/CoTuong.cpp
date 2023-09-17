#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class Co
{
	protected:
		char mau[6];//Mau quan co
	public:
		virtual void nhap()
		{
			fflush(stdin);
			cout<<"\nChon phe? (Den / Trang): ";cin.getline(this->mau, 6);
		}
		virtual void xuat()
		{
			cout<<"->Quan "<<this->mau;	
		}
		virtual int toa_do_x();
		virtual int toa_do_y();
}; 
class Vua :public Co
{
	protected:
	public:
	 	int toa_do_x()
		{
			if(strcmpi(this->mau,"trang")==0){
				return 1;
			}else{
				return 10;
			}
		}
		int toa_do_y()
		{
			return 5;
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nVua: di tung o mot, di ngang hoac doc. Luon phai o trong pham vi cung va khong duoc ra ngoai"<<endl;
			cout<<"\nVi tri: ("<<toa_do_x()<<" , "<<toa_do_y()<<")"<<endl;
		}
};
class Tuong: public Co
{
	protected:
		int tuong1, tuong2;
		int chon1;
	public:
		void nhap()
		{
			Co::nhap();
			cout<<"\n1.Tuong 1, 2. Tuong 2: ";cin>>chon1;
		}
		int toa_do_x()
		{	
			if(strcmpi(this->mau,"trang")==0){
				return 1;
			}else{
				return 10;
			}	
		}
		int toa_do_y()
		{
			if(chon1==1){
				return 3;
		  	 }else{
				return 7;
			}
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nTuong: cheo 2 o (ngang 2 hoac doc 2) cho moi nuoc di. Chi duoc phep di mot ben cua ban co. Khong duoc di chuyen san nua ban co cua doi phuong"<<endl;
			cout<<"\nVi tri: ("<<toa_do_x()<<" , "<<toa_do_y()<<")"<<endl;
		}   
}; 
class Si :public Co
{
	protected:
		int si1, si2;
		int chon2;
	public:
		void nhap()
		{
			Co::nhap();
			cout<<"\n1.Si 1, 2. Si 2: ";cin>>chon2;
		}
		int toa_do_x()
		{
			if(strcmp(this->mau,"den")==0)
			{
				return 10;
			}else{
				return 1;
			}
		}
		int toa_do_y()
		{
			if(chon2==1){
				return 4;
			}else{
				return 6;
			}
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nSi: di xeo mot o moi nuoc. Luon phai o trong cung nhu Tuong"<<endl;	
			cout<<"\nVi tri: ("<<toa_do_x()<<" , "<<toa_do_y()<<")"<<endl;
		}
};
class Xe :public Co
{
	protected:
		int xe1, xe2;
	int chon3;
	public:
		void nhap()
		{
			Co::nhap();
			cout<<"\n1.Xe 1, 2. Xe 2: ";cin>>chon3;
		}
		int toa_do_x()
		{
			if(strcmpi(this->mau,"den")==0)
			{
				return 10;
			}else{
				return 1;
			}
		}
		int toa_do_y()
		{
			if(chon3==1){
				return 1;
			}else{
				return 9;
			}
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nXe: di ngang hoac doc. Mien la khong bi quan khac quan duong tu diem di den diem den"<<endl;
			cout<<"\nVi tri: ("<<toa_do_x()<<" , "<<toa_do_y()<<")"<<endl;
		}
};
class Ma  :public Co
{
	protected:
		int ma1, ma2;
		int chon4;
	public:
		void nhap()
		{
			Co::nhap();
			cout<<"\n1. Ma 1, 2. Ma 2: ";cin>>chon4;
		}
		int toa_do_x()
		{
			if(strcmpi(this->mau,"trang")==0){
				return 1;
			}else{
				return 10;
			}
		}
		int toa_do_y()
		{
			if(chon4==1){
				return 2;
			}else{
				return 8;
			}
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nMa: di ngang 2 o va doc 1 o (doc 2 o va ngang 1 o) cho moi nuoc.";
			cout<<"\nNeu co quan ben canh can duong di ngang 2 (doc 2). Ma bi can khong duoc di"<<endl;
			cout<<"\nVi tri: ("<<toa_do_x()<<","<<toa_do_y()<<")"<<endl;
		}
};
class Phao  :public Co
{
	protected:
		int phao1, phao2;
		int chon5;
	public:
		void nhap()
		{
			Co::nhap();
			cout<<"\n1.Phao 1, 2. Phao 2: ";cin>>chon5;
		}
		int toa_do_x()
		{
			if(strcmpi(this->mau,"trang")==0){
				return 3;
			}else{
				return 8;
			}
		}
		int toa_do_y()
		{
			if(chon5==1){
				return 2;
			}else{
				return 8;
			}
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nPhao: di ngang va doc giong xe.";
			cout<<" Neu muon an quan phai nhay qua dung mot quan nao do.";
			cout<<" Khi khong an quan, tat ca nhung diem tu cho di den cho den khong duoc co quan can"<<endl;
			cout<<"\nVi tri: ("<<toa_do_x()<<" , "<<toa_do_y()<<")"<<endl;
		}
};
class Tot  :public Co
{
	protected:
		int t1, t2, t3, t4, t5; // 5 quan tot
		int chon6;
	public:
		void nhap()
		{
			Co::nhap();
			cout<<"\n1.Tot 1, 2. Tot 2: ";cin>>chon6;
		}
		int toa_do_x()
		{
			if(strcmpi(this->mau,"trang")==0){
				return 4;
			}else{
				return 7;
			}
		}
		int toa_do_y()
		{
			if(chon6==1){
				return 1;
			}else if(chon6==2){
				return 3;
			}else if(chon6==3){
				return 5;
			}else if(chon6==4){
				return 7;
			}else{
				return 9;
			}
		}
		void xuat()
		{
			Co::xuat();
			cout<<"\nTot: di mot o moi nuoc. Neu tot chua vuot qua song, chi co the di thang tien. Sau khi vuot song, co the di ngang 1 buoc hay thang 1 buoc cho moi nuoc."<<endl;
			cout<<"\nVi tri: ("<<toa_do_x()<<" , "<<toa_do_y()<<")"<<endl;
		}
};

void menu()
{
	cout<<"\n1.Vua"<<endl;
	cout<<"\n2.Si"<<endl;
	cout<<"\n3.Tuong"<<endl;
	cout<<"\n4.Xe"<<endl;
	cout<<"\n5.Ma"<<endl;
	cout<<"\n6.Phao"<<endl;
	cout<<"\n7.Tot"<<endl;
	cout<<"\n8.Thoat"<<endl;
}
class QuanLy
{
	Co *a[100];
	int n;
	public:
		void nhap()
		{
			int chon;
			int i=0;
			while(1)
			{
				menu();
				cout<<"\nChon mot quan co: ";cin>>chon;
				if(chon==1) a[i] = new Vua();
		 		else if(chon==2) a[i] = new Si();
			 	else if(chon==3) a[i] = new Tuong();
			 	else if(chon==4) a[i] = new Xe();
			 	else if(chon==5) a[i] = new Ma();
			 	else if(chon==6) a[i] = new Phao();
			 	else if(chon==7) a[i] = new Tot();
			 	else break;
			 	a[i]->nhap();
			 	i++;
			}
			n=i;
		}
		void xuat()
		{
			cout<<"\n_____________________________________________________________________________________________"<<endl;
			for(int i=0; i<n; i++)
			{
				a[i]->xuat();
			}
			cout<<"\n_____________________________________________________________________________________________"<<endl;
		
		}
};
int main()
{
	QuanLy q;
	q.nhap();
	q.xuat();
	return 0;	
} 
