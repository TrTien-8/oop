#include<bits/stdc++.h>
using namespace std;
class Nguoi{
	protected:
		string ma, hoten;
		float luong;
		static int tongsodt;
	public:
		//ham tao
		Nguoi(){
			ma=hoten="";
			luong=0;
		}
		static int returndem(){
			return tongsodt;
		}
		virtual void nhap(){
			cout<<"			NHAP THONG TIN "<<endl;
			cout<<" 	-Nhap ma nhan vien: "; cin>>ma;
			cout<<" 	 -Nhap ten nhan vien: "; fflush(stdin); getline(cin, hoten);
			tongsodt++;
		}
		void dongke(){
			for(int i=0; i<48; i++){
				cout<<"-";
			}
			cout<<endl;
		}
		void xuat(int i){
			dongke();
			cout<<"|"<<setw(5)<<left<<i+1<<"|"<<setw(10)<<left<<ma<<"|"<<setw(20)<<left<<hoten<<"|"<<setw(10)<<left<<luong<<"|"<<endl;
			dongke();
		}
		friend void swap(Nguoi &a,Nguoi &b){
			Nguoi temp;
			temp.hoten=a.hoten; temp.ma=a.ma; temp.luong=a.luong;
			a.hoten=b.hoten; a.ma=b.ma; a.luong=b.luong;
			b.hoten=temp.hoten; b.ma=temp.ma; b.luong=temp.luong;
		}
		float returnluong(){
			return luong;
		}
		//ham huy
		~Nguoi(){};
};
int Nguoi::tongsodt=0;
bool sosanh(Nguoi &a, Nguoi &b){
	return a.returnluong()>b.returnluong();
}
class NhanvienHC: public Nguoi{
	private:
		int hsl;
		float luongcoban, phucap;
	public:
		void nhap(){
			Nguoi::nhap();
			cout<<"	-Nhap he so luong: ";cin>>hsl;
			cout<<"	-Nhap luong co ban: ";cin>>luongcoban;
			cout<<" 	-Nhap phu cap: "; cin>>phucap;
			luong=hsl*luongcoban+phucap;
		}
};
class Nhanvienlamca: public Nguoi{
	private:
		int soca;
		float tien1ca, tienan, phucapdochai;
	public:
		void nhap(){
			Nguoi::nhap();
			cout<<"	-Nhap so ca lam: "; cin>>soca;
			cout<<"	-Nhap tien lam mot ca: "; cin>>tien1ca;
			cout<<"	-Nhap tien an mot ca: "; cin>>tienan;
			cout<<"	-Nhap tien phu cap doc hai: "; cin>>phucapdochai;
			luong=soca*tien1ca+tienan+phucapdochai;
		}
		
};
class quanli{
	private:
		vector<Nguoi *>dsnv;
	public:
		void menu(){
			cout<<"******************************************"<<endl;
			cout<<"*"<<" 		CHON MUC DUOI DAY"<<"        *"<<endl;
			cout<<"*"<<" 1. Them nhan vien hanh chinh "<<"          *"<<endl;
			cout<<"*"<<" 2. Them nhan vien lam ca "<<"              *"<<endl;
			cout<<"*"<<" 3. In bang"<<"                             *"<<endl;
			cout<<"*"<<" 0. Thoat "<<"                         	 *"<<endl;
			cout<<"******************************************"<<endl;
		}
		void sort(){
			for(int i=0; i<dsnv.size()-1;i++){
				for(int j=i+1; j<dsnv.size(); j++){
					if(sosanh(*dsnv[i], *dsnv[j])==false){
						swap(*dsnv[i], *dsnv[j]);
					}
				}
			}
		}
		void inbang(){
			dongke();
			cout<<"|"<<setw(5)<<left<<"STT"<<"|"<<setw(10)<<left<<"Ma ho so"<<"|"<<setw(20)<<left<<"Ho ten"<<"|"<<setw(10)<<left<<"Luong"<<"|"<<endl;
			for(int i=0; i<dsnv.size(); i++){
				dsnv[i]->xuat(i);
			}
		}
		void dongke(){
			for(int i=0; i<48; i++){
				cout<<"-";
			}
			cout<<endl;
		}
		void thuchien(){
			int chon=1;
			Nguoi *a;
			while(chon!=0){
				cout<<"	Ban chon: "; cin>>chon;
				switch(chon){
					case 1:{
						a=new NhanvienHC();
						a->nhap();
						dsnv.push_back(a);
						cout<<"		NHAN VIEN DA DUOC THEM !"<<endl;
						break;
					}
					case 2:{
						a=new Nhanvienlamca();
						a->nhap();
						dsnv.push_back(a);
						cout<<"		NHAN VIEN DA DUOC THEM !"<<endl;	
						break;
					}
					case 3:{
						system("cls");
						sort();
						cout<<endl<<"		Tong so doi tuong: "<<Nguoi::returndem()<<endl;
						inbang();
						break;
					}
					default:{
						break;
					}
				}
			}
		}
};
int main(){
	quanli *a=new quanli();
	a->menu();
	a->thuchien();
}

