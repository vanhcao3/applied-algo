#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i]; //Toa do x khi di chuyen
        int yy = Y[k-1] + hy[i]; //Toa do y khi di chuyen
        if((!mark[xx][yy]) && (xx >= 1) && (xx <= n) 
                           && (yy >= 1) && (yy <= n)){
            X[k] = xx; //Toa do cot lan di chuyen thu k = xx
            Y[k] = yy; //Toa do hang lan di chuyen thu k = yy
            mark[xx][yy] = 1; //Danh dau toa do da di chuyen
            if(k == n*n) //Neu di qua het cac o thi in ra ket qua
                print_sol();
            else
                TRY(k+1);//Neu chua thi tim loi giai thu k+1
            mark[xx][yy] = 0; //Thiet lap lai mang danh dau
        }                     //khi da di qua het cac o     
        
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
