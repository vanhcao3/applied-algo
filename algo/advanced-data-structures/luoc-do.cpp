#include <bits/stdc++.h>
using namespace std;
//Cao Viet Anh 20215299
int main(){
	int nn = 1;
	while(1){
		cout << "Cao Viet Anh 20215299" << endl;
		cout << "Test " << nn << ":" << endl;
		//Nhap vao so luong cot chu nhat
		int n, max_area = 0; 
		cin >> n;
		//Nhap vao chieu cao cua cac cot
		vector<int> height(n);
		for(int i=0; i<n; i++){
			int input;
			cin >> input;
			height[i] = input;
		}
		stack<int> s; //Dung stack de luu chuoi khong giam cua chieu cao
		for(int i=0; i<n; i++){ //Voi moi cot
			//Neu chieu cao cua vi tri i nho hon chieu cao cua vi tri top() cua stack
			while(!s.empty() && height[i]<height[s.top()]){
			//i la bien ben phai cua mot chuoi khong giam, 	
				int h = height[s.top()];//Tinh dien tich doi voi moi phan tu trong stack 
				s.pop(); //Dua phan tu do ra khoi stack
				//Tinh do dai
				int l = s.empty()? i : i- s.top() - 1; 
				//Neu stack rong thi phan tu vua duoc pop la phan tu nho nhat toi thoi diem dang xet
				//Do do do dai tinh tu phan tu dau tien toi phan tu vua duoc pop
				//Neu stack khac rong thi phan tu vua duoc pop lon hon phan tu top moi, co nghia phan tu top moi la bien ben trai cua hinh chu nhat, nen do dai tinh tu bien ben trai den bien ben phai
				max_area = max(max_area, h*l); //Cap nhat dien tich lon nhat tung duoc xet
			}
			s.push(i);
		}
		//Tinh toan cac phan tu con lai trong stack
		while (!s.empty()){
		//Cac phan tu trong stack la mot chuoi khong giam	
			int h = height[s.top()]; //Tinh dien tich doi voi phan tu top cua stack
			s.pop();
			//Neu stack rong tuc la phan tu vua duoc pop la phan tu nho nhat duoc xet
			//Vi vay do dai tinh tu phan tu dau tien toi phan tu vua duoc pop
			//Neu stack khac rong thi ton tai phan tu nho ho phan tu vua duoc pop
			//Vi vay do dai duoc tinh tu phan tu top moi cho den phan tu cuoi
			int l = s.empty()? n : n - s.top() - 1;
			max_area = max(max_area, h*l); //Cap nhat dien tich lon nhat tung duoc xet
		}
		cout << max_area << endl; //In ra dap an
		nn++;
	}
	return 0;
} //Cao Viet Anh 20215299
