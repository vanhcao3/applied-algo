#include<bits/stdc++.h>
using namespace std;
//Cao Viet Anh 20215299
const int MAX = 10000;
int n, r; 
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_price;
int sum_price;
int start, destination, numberOfPoint;

void input(){ //Nhap du lieu
    cin >> n >> r; //Nhap vao so luong dia diem va so lo trinh can di
    for(int i=0; i<n; i++) //Nhap vao ma tran chi phi di lai
        for(int j=0; j<n; j++){ //cua cac dia diem
            cin >> price[i][j]; //Chi phi di tu dia diem i sang dia diem j
        }
}

bool check(int a, int i){ //Kiem tra su hop le cua loi gia cap  a
    if(visited[vt[i]]) return false; //Neu da tham dia diem i thi bo qua
    if(price[x[a-1]][vt[i]] == 0) return false; //Neu dia diem dang xet trung voi dia diem truoc do thi bo qua
    return true; //Neu khong vi pham dieu gi thi ghi nhan loi giai cap a
}

void solution(){ //Ghi nhan loi giai va tinh toan do dai duong di ngan nhat cua lo trinh
    if(price[x[numberOfPoint-2]][destination] == 0) 
		return; //Neu thanh pho trung nhau thi khong ghi nhan loi giai
	//Neu duong di la hop le thi cap nhat do dai duong ngan nhat
    min_price = min(min_price, sum_price + price[x[numberOfPoint-2]][destination]);
}

void TRY(int a){ //De quy quay lui liet ke ra tat ca cac dap an
    for(int i=1; i<numberOfPoint-1; i++){
        if(check(a, i)){ //Neu duoc phep di qua thanh pho i
            visited[vt[i]] = true; //Danh dau thanh pho i la da tham
            sum_price += price[x[a-1]][vt[i]]; //Cap nhat chi phi di qua i
 
            x[a] = vt[i]; 
            if(a == numberOfPoint-2) //Neu da di qua tat ca thanh pho
				solution();	//Ghi nhan loi giai
            else TRY(a+1); //Neu khong tim loi giai cap cao hon
            
			//Neu quay lui, khoi phuc trang thi loi giai cap hien tai
            visited[vt[i]] = false; 
            sum_price -= price[x[a-1]][vt[i]];
        }
    }
}

int main(){
	cout << "Cao Viet Anh 20215299" << endl;
    string str; 
    //Nhap du lieu
    input();
    getline(cin,str); 

    while(r > 0){
        min_price = INT_MAX; 
        sum_price = 0;
		
		cout << "Lo trinh: ";
        getline(cin, str); //Nhap lo trinh 

        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" "))); //Chuyen lo trinh tu dang xau thanh kieu so nguyen
            //Day lo trinh thanh phan ra bien tmp
            int tmp = 0; 
            convert >> tmp; 
            vt.push_back(tmp - 1); //Dua lo trinh vao mang 
			
            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); // Update string
            }
        }

        // Bat dau khoi tao cac du lieu can thiet truoc khi quay lui
        start = vt[0]; //Diem bat dau dau
        destination = vt[vt.size()-1]; //Diem dich
        numberOfPoint = vt.size(); //So diem phai di qua
        x[0] = start; x[numberOfPoint-1] = destination;
        
        for(int i=0; i<n; i++)
            visited[i] = false; //Khoi tao mang danh dau

        TRY(1); //De quy quay lui tim loi giai

        // In ra ket qua
        if(min_price == INT_MAX) cout << "0" << endl;
        else cout << "Chi phi di lai: " << min_price << endl;

        // Khoi phuc trang thai de chuyen sang lo trinh tiep theo
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}//Cao Viet Anh 20215299

