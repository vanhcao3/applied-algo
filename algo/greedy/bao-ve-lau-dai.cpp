#include <bits/stdc++.h>
using namespace std;
//Cao Viet Anh 20215299

//Marcro de doc code cho de hieu
#define enemy first 
#define strength second 

class comparator{ //comparator cho hang doi uu tien
	public: //uu tien cac buc tuong co ai hoac ki lon
	bool operator()(pair<int, int> a, pair<int, int> b){
		int x = min(a.enemy, a.strength), y = min(b.enemy, b.strength);
		return x < y; //Dua phan tu sau len dau cua hang doi neu no co gia tri lon hon phan tu truoc
	}
};

int main(){
	int nn = 1;
	while(1){
		cout << "Cao Viet Anh 20215299" << endl;
		cout << "Test " << nn << ":" << endl;
		int n, s; //n doan tuong, s quan linh
		int defended = 0, count = 0; //defended-so ke dich bi day lui, count-tong so dich
		
		cin >> n >> s; //Nhap vao n, s
		//Hang doi uu tien, uu tien bao ve cac doan tuong de bao ve nhat(co ai hoac ki lon)
		priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> wall;
		//Nhap vao so ke dich o moi doan tuong va kha nang bao ve cua quan linh o do
		for(int i = 0; i< n; i++){
			int a, b;
			cin >> a >> b; 
			count += a; //Tinh tong so ke dich
			wall.push({a,b});
		}
		
		
		while(!wall.empty() && s > 0){//Khi chua xem xet het
			//Xem xet cac phan tu theo thu tu uu tien
			pair<int, int> temp = wall.top(); wall.pop();
			//Neu tong so ke dich nho hon so ke dich ma 1 linh co the tieu diet duoc
			if(temp.enemy <= temp.strength){
				defended += temp.enemy; //Giai quyet doan tuong do ngay va luon
			} else{ //Neu nguoc lai
				int nenemy = temp.enemy - temp.strength; 
				//Bo tri 1 linh va dua trang thai moi vao hang doi
				wall.push(make_pair(nenemy, temp.strength));
				defended += temp.strength;//Tang so luong dich da bi tieu diet boi 1 linh do
			}
			s -= 1; //Giam so luong quan dang ranh
		}
		//Sau khi da bo tri xong linh, dem so luong quan dich con sot lai
		cout << "output = " << count - defended << endl;
		nn++;
	}
	return 0;
} //Cao Viet Anh 20215299
