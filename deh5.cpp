#include<bits/stdc++.h>
using namespace std;
class Sach{
	protected:
		int ms,giabia;
		string ten;
	public:
		Sach(){ //ham tao
			ms=giabia=0;
			ten="";
		}
		~Sach(){  //ham huy
		}
		virtual void nhap(){
			cout<<"\nNhap vao ma so sach: ";cin>>ms;
			cout<<"Nhap vao ten sach: ";fflush(stdin);getline(cin,ten);
		}
		int printgia(){
			return giabia;
		}
		string printten(){
			return ten;
		}
		string Quatang(){ //ham thanh phan qua tang
			if(giabia>=500000) return "Qua dac biet.";
			else if(giabia>=200000&&giabia<500000) return "Qua tang.";
			else return "Khong tang qua";
		}
		void print(int i){
			cout<<"\n|"<<setw(4)<<left<<i+1<<"|"<<setw(29)<<left<<ten<<"|"<<setw(14)<<left<<giabia<<"|"<<setw(34)<<left<<Quatang()<<"|";
			cout<<"\n--------------------------------------------------------------------------------------";
		}
		friend void sapxep(Sach &i,Sach &j){
			Sach temp;
			temp.ten=i.ten;temp.giabia=i.giabia;temp.Quatang()=i.Quatang();
			i.ten=j.ten;i.giabia=j.giabia;i.Quatang()=j.Quatang();
			j.ten=temp.ten;j.giabia=temp.giabia;j.Quatang()=temp.Quatang();
		}
};
bool sosanh(Sach *a,Sach *b){//dinh nghia toan tu ">"
	return a->printgia()>b->printgia();
}
class Sachvb:public Sach{
	private:
		int dongiatrang,sotrang,giavebia;
	public:
		void nhap(){
			Sach::nhap();
			cout<<"Nhap vao don gia trang: ";cin>>dongiatrang;
			cout<<"Nhap vao so trang: ";cin>>sotrang;
			cout<<"Nhap vao gia ve bia: ";cin>>giavebia;
			giabia=dongiatrang*sotrang+giavebia;
		}
};
class Sachkvb:public Sach{
	private:
		int dongia,so;
	public:
		void nhap(){
			Sach::nhap();
			cout<<"Nhap vao don gia trang: ";cin>>dongia;
			cout<<"Nhap vao so trang: ";cin>>so;
			giabia=dongia*so;
		}
};
int main(){
	vector<Sach *>dss;
	int ktra=1;
	Sach *s;
	cout<<"***** CHAO MUNG BAN--HAY CHON LOAI SACH*****";
	cout<<"\n1.   SACH_VE_BIA.";
	cout<<"\n2.   SACH_KHONG_VE_BIA";
	while(1){
		int kt;
		cout<<"\n\nLoai sach ban muon la: ";cin>>kt;
		if(kt==1){
			s=new Sachvb;
			s->nhap();
			dss.push_back(s);
			cout<<"\n~~~~~SACH DA DUOC THEM THANH CONG~~~~~";
		}
		else if(kt==2){
			s=new Sachkvb;
			s->nhap();
			dss.push_back(s);
			cout<<"\n~~~~~SACH DA DUOC THEM THANH CONG~~~~~";
		}
		else break;
	}
	for(int a=0;a<dss.size()-1;a++){
		for(int b=a+1;b<dss.size();b++){
			if(dss[a]->printten()>dss[b]->printten()) sapxep(*dss[a],*dss[b]);
		}
	}
	cout<<"BANG: \n\n";
	cout<<"\n______________________________________________________________________________________\n";
	cout<<setw(5)<<left<<"|STT"<<setw(30)<<left<<"|Ten sach"<<setw(15)<<left<<"|Gia bia"<<setw(35)<<left<<"|Qua tang"<<"|";
	cout<<"\n______________________________________________________________________________________";
	for(int i=0;i<dss.size();i++){
		dss[i]->print(i);
	}
}
