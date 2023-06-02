#include <iostream.h>
#include <string.h>
class NotNhac
{
	private:
		int chon;
	public:
		void nhap()
		{
			cout<<"\nChon not nhac: (Do, Re, Mi, Fa, Sol, La, Si, ~): "<<endl;
			cout<<"\nNhan de chon:	(1 , 2 , 3 , 4 , 5  , 6 , 7 , 8): ";cin>>this->chon;
		}
		void xuat()
		{
			if(chon==1){
				cout<<"C";
			}else if(chon==2){
				cout<<"D";
			}else if(chon==3){
				cout<<"E";
			}else if(chon==4){
				cout<<"F";
			}else if(chon==5){
				cout<<"G";
			}else if(chon==6){
				cout<<"A";
			}else if(chon==7){
				cout<<"B";
			}else{
				cout<<"Z";
			}
		}	
		int get_chon()
		{
			return chon;
		}
};
class TruongDo: public NotNhac
{
	private:
		int chon1;
	public:	
		void nhap()
		{
			NotNhac::nhap();
			cout<<"\nChon truong do: (Tron, Trang, Den, Moc don, Moc doi, Moc tam, Moc tu): "<<endl;
			cout<<"\nNhan de chon:	 (1   , 2    , 3  , 4      , 5      , 6      , 7     ): ";cin>>this->chon1;
		}
		void xuat()
		{
			NotNhac::xuat();
			if(chon1==1){
				cout<<"4- ";
			}else if(chon1==2){
				cout<<"2- ";
			}else if(chon1==3){
				cout<<"1- ";
			}else if(chon1==4){
				cout<<"1/2- ";
			}else if(chon1==5){
				cout<<"1/4- ";
			}else if(chon1==6){
				cout<<"1/8- ";
			}else{
				cout<<"1/16- ";
			}
		}	
		int get_chon1()
		{
			return chon1;
		}
		friend int tim_Z(TruongDo a[], int n);
		friend int max_cao_do(TruongDo a[], int n);
};
int tim_Z(TruongDo a[], int n)
{
	int d=0;
	for(int i=0; i<n; i++)
	{	
		if(a[i].get_chon1()==3 && a[i].get_chon()==8)
		{
			d++;
		}
	}
	cout<<"\nSo luong dau lang den co trong ban nhac: "<<d<<endl;
}
int max_cao_do(TruongDo a[], int n)
{
	int max=a[0].get_chon();
	for(int i=0; i<n; i++)
	{	
		if(a[i].get_chon()>max)
		{
			max=a[i].get_chon();
		}
	}
	return max;	
}
int main()
{
	TruongDo *a;
	int n;
	cout<<"\nSo not nhac n= ";cin>>n;
	a= new TruongDo[n];
	for(int i=0; i<n; i++)
	{
		a[i].nhap();
	}
	for(int i=0; i<n; i++)
	{
		a[i].xuat();
	}
	tim_Z(a,n);
	cout<<"\nNot nhac co cao do cao nhat trong ban nhac: ";
	for(int i=0; i<n; i++)
	{
		if(a[i].get_chon()==max_cao_do(a,n)){
			a[i].xuat();
		}
	}
	return 0;
}