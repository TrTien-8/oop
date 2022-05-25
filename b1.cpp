#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
class giangvien {
	protected:
		string ma_so, ho_ten;
		float gio_nghien_cuu;
		
	public:
		// ham tao ko tham so
		giangvien() {
			ma_so = ho_ten = "";
			gio_nghien_cuu = 0;
		}
		
		float returntime() {
			return gio_nghien_cuu;
		}
		
		// ham tao co tham so
		giangvien(string ma_so, string ho_ten, float gio_nghien_cuu) {
			this->ma_so = ma_so;
			this->ho_ten = ho_ten;
			this->gio_nghien_cuu = gio_nghien_cuu;
		}
		// ham nhap
		virtual void nhap() {
			cout << "Nhap ma so giang vien: " << endl; cin >> ma_so;
			cout << "Nhap vao ten giang vien: " << endl; fflush(stdin); getline(cin, ho_ten);
			cout << "Nhap vao gio nghien cuu: " << endl; cin >> gio_nghien_cuu;	
		}
		// ham huy
		~giangvien() {	
		};
		// cau 2
		string xeploai() {
			if(gio_nghien_cuu < 500) return "Khong hoan thanh";
			else if(gio_nghien_cuu > 500 && gio_nghien_cuu <= 1000) return "Hoan thanh";
			else return "Hoan thanh xuat xac";
		}
		
		void xuat(int i) {
			cout << "|" << setw(5) << left << i+1 << "|" << setw(10) << left << ma_so << "|" << setw(15) << left << ho_ten << "|" 
			<< setw(15) << left << gio_nghien_cuu << "|" << setw(20) << left << xeploai() << "|"<< endl;
			dongke();
		}
		friend void swap(giangvien &a, giangvien &b) {
			giangvien temp;
			temp.ho_ten = a.ho_ten; temp.ma_so = a.ma_so; temp.gio_nghien_cuu = a.gio_nghien_cuu; temp.xeploai() = a.xeploai();
			a.ho_ten = b.ho_ten; a.ma_so = b.ma_so; a.gio_nghien_cuu = b.gio_nghien_cuu; a.xeploai() = b.xeploai();
			b.ho_ten = temp.ho_ten; b.ma_so = temp.ma_so; b.gio_nghien_cuu = temp.gio_nghien_cuu; b.xeploai() = temp.xeploai();
		}
		void dongke() {
			for(int i = 0; i < 70; i++) {
				cout << "-";
			}
			cout << endl;
		}
};

//cau 3
bool sosanh(giangvien &a, giangvien &b) {
	return a.returntime() > b.returntime();
}

//cau 4
class giang_vien_co_huu: public giangvien {
	private:
		float so_bao, gio_bao, hdnghiencuu, hsnghiencuu;
	public:
		void nhap() {
			giangvien::nhap();
			cout<<"Nhap so bai bao: "; cin >> so_bao;
			cout<<"Nhap gio bai bao: "; cin >> gio_bao;
			cout<<"Nhap huong dan nghien cuu: "; cin >> hdnghiencuu;
			cout<<"Nhap he so nghien cuu: "; cin >> hsnghiencuu;
			gio_nghien_cuu = so_bao * gio_bao + hdnghiencuu * hsnghiencuu;
		}
};

class giang_vien_kiem_giang: public giangvien {
	private:
		float so_bao, gio_bao, giokiemgiang;
	public:
		void nhap() {
			giangvien::nhap();
			cout << "Nhap so bai bao: "; cin >> so_bao;
			cout << "Nhap so gio bao: "; cin >> gio_bao;
			cout << "Nhap so gio kiem giang: "; cin >> giokiemgiang;
			gio_nghien_cuu = so_bao * gio_bao + giokiemgiang;
		}
};

class quanli {
	private:
		vector  <giangvien *> dsgv;
	public:
		void menu() {
			cout << "          HAY CHON MUC DUOI DAY         " << endl;
			cout << "1. Nhap giao vien co huu" << endl;
			cout << "2. Nhap giao vien kiem giang" << endl;
			cout << "0. Thoat" << endl;
		}
		
		void inbang() {
			dongke();
			cout << "|" << setw(5) << left << "STT" << "|" << setw(10) << left << "MA SO" << "|" << setw(15) << left << "HO TEN" << "|" 
			<< setw(15) << left << "GIO NGHIEN CUU" << "|" << setw(20) << left << "XEP LOAI" << "|"<< endl;
			dongke();
			for (int i = 0; i < dsgv.size(); i++) {
				dsgv[i]->xuat(i);
			}
		}
		
		void dongke() {
			for(int i = 0; i < 70; i++) {
				cout << "-";
			}
			cout << endl;
		}
		
		void sort() {
			for(int i=0; i<dsgv.size()-1; i++) {
				for(int j=i+1; j<dsgv.size(); j++) {
					if(sosanh(*dsgv[i], *dsgv[j]) == false) swap(*dsgv[i], *dsgv[j]);
				}
			}
		}
		
		void thuchien() {
			int chon = 1;
			giangvien *a;
			while(chon != 0) {
				cout << "Nhap lua chon cua ban: "; cin >> chon;
				switch(chon) {
					case 1: {
						a = new giang_vien_co_huu();
						a->nhap();
						dsgv.push_back(a);
						cout << " GIANG VEIN DA THEM THANH CONG !" << endl;
						break;
					}
					case 2: {
						a = new giang_vien_kiem_giang();
						a->nhap();
						dsgv.push_back(a);
						cout << "GIANG VIEN DA THEM THANH CONG !" << endl;
						break;
					}
					default: {
			
						break;
					}
				}
			}
			system("cls");
			sort();
			inbang();
		}
};

int main() {
	quanli *a = new quanli();
	a->menu();
	a->thuchien();
}










