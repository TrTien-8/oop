#include<bits/stdc++.h>
using namespace std;
class giangvien{
	protected:
		string ma_so, ho_ten;
		float gio_nghien_cuu;
		static int tongdoituong;
	public:
		float returngio(){
			return gio_nghien_cuu;
		}
		static int returndem(){
			return tongdoituong;
		}
		giangvien(){
			ma_so=ho_ten="";
			gio_nghien_cuu=0;
		}
		virtual void nhap(){
			cout<<"		NHAP THONG TIN GIAO VIEN "<<endl;
			cout<<"	-Nhap ma so giang vien: "; cin>>ma_so;
			cout<<"	-Nhap ho ten giang vien: "; fflush(stdin); getline(cin, ho_ten);
			tongdoituong++;
		}
		virtual void xuat(int i){
			dongke();
			cout<<"|"<<setw(5)<<left<<i<<"|"<<setw(10)<<left<<ma_so<<"|"<<setw(25)<<left<<ho_ten<<"|"<<setw(20)<<left<<gio_nghien_cuu<<"|"<<endl;
			dongke();
		}
		friend void hoanvi(giangvien &a, giangvien &b){
			giangvien temp;
			temp.gio_nghien_cuu=a.gio_nghien_cuu;temp.ho_ten=a.ho_ten; temp.ma_so=a.ma_so;
			a.gio_nghien_cuu=b.gio_nghien_cuu;a.ho_ten=b.ho_ten; a.ma_so=b.ma_so;
			b.gio_nghien_cuu=temp.gio_nghien_cuu;b.ho_ten=temp.ho_ten; b.ma_so=temp.ma_so;
		}
		void dongke(){
			for(int i=0; i<65; i++){
				cout<<"-";
			}
			cout<<endl;
		}
		giangvien *next;
		~giangvien(){	
		}
};
bool sosanh(giangvien &a, giangvien &b){
	return a.returngio()>b.returngio();
}
int giangvien::tongdoituong=0;
class giang_vien_co_huu: public giangvien{ 
	private:
		float sobaibao, giobaibao, hdnghiencuu, hsnghiencuu;
	public:
		float returngio(){
			return gio_nghien_cuu;
		}
		void nhap(){
			giangvien::nhap();
			cout<<" 	-Nhap so bai bao: "; cin>>sobaibao;
			cout<<" 	-Nhap gio bai bao: "; cin>>giobaibao;
			cout<<" 	-Nhap huong dan nghien cuu: "; cin>>hdnghiencuu;
			cout<<" 	-Nhap he so nghien cuu: "; cin>>hsnghiencuu;
			gio_nghien_cuu=sobaibao*giobaibao+hdnghiencuu*hsnghiencuu;
		}
};
class giang_vien_kiem_giang:public giangvien{
	private:
		float sobaibao, giobaibao, giokiemgiang;
	public:
		float returngio(){
			return gio_nghien_cuu;
		}
		void nhap(){
			giangvien::nhap();
			cout<<" 	-Nhap so bai bao: "; cin>>sobaibao;
			cout<<" 	-Nhap gio bai bao: "; cin>>giobaibao;
			cout<<" 	-Gio kiem giang: "; cin>>giokiemgiang;
			gio_nghien_cuu=sobaibao*giobaibao+giokiemgiang;
		}
};
class quanli{
	public:
		void dongke(){
			for(int i=0; i<65;i++){
				cout<<"-";
			}
			cout<<endl;
		}
		void themgiangvienmoi(){
			giangvien *dau=NULL, *cuoi;
	giangvien *a;
	char ok='c';
	while(ok=='c'){
		cout<<"			NHAP LUA CHON DUOI DAY !"<<endl;
		cout<<" 1. Giang vien co huu. "<<endl;
		cout<<" 2. Giang vien kiem giang. "<<endl;
		int chon;
		cout<<"Nhap lua chon cua ban: "; cin>>chon;
		switch(chon){
			case 1:{
				a=new giang_vien_co_huu();
				a->nhap();
				if(dau==NULL){
					dau=a;
					cuoi=a;
				}
				else{
					cuoi->next=a;
					cuoi=a;
				}
				break;
			}
			case 2:{
				a=new giang_vien_kiem_giang();
				a->nhap();
				if(dau==NULL){
					dau=a;
					cuoi=a;
				}
				else{
					cuoi->next=a;
					cuoi=a;
				}
				break;
			}
		}
		cout<<"	 	GIANG VIEN DA DUOC THEM THANH CONG !!"<<endl;
		cout<<"Ban co muon them giang vien (nhap c neu co, nhap k neu khong): "; cin>>ok;
	}
	giangvien *i, *j;
	i=dau;
	while(i!=NULL){
		j=i->next;
		while(j!=NULL){
			if(sosanh(*i, *j)==false){
				hoanvi(*i, *j);
			}
			j=j->next;
		}
		i=i->next;
	}
	system("cls");
	cout<<"		Tong so giang vien: "<<giangvien::returndem()<<endl;
	giangvien *duyet;
	duyet=dau;
	cout<<"			DANH SACH SAP XEP THEO SU GIAM DAN "<<endl;
	int t=1;
	dongke();
	cout<<"|"<<setw(5)<<left<<"STT"<<"|"<<setw(10)<<left<<"Ma so"<<"|"<<setw(25)<<left<<"Ho ten"<<"|"<<setw(20)<<left<<"Gio nghien cuu"<<"|"<<endl;
	while(duyet!=NULL){
		duyet->xuat(t);
		duyet=duyet->next;
		t++;
	}
}
};
int main(){
	quanli *a=new quanli();
	a->themgiangvienmoi();
}
