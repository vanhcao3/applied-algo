#include <bits/stdc++.h>
using namespace std;
//Cao Viet Anh 20215299
int w, h;
int table[601][601];

void init() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            table[i][j] = i*j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //int w, h; Loi logic, khai bao bien cuc bo nen bien toan cuc se khong duoc su dung
    int m; //Chi khai bao m
    cout << "Cao Viet Anh 20215299\n";
    cin >> w >> h;
    cin >> m;
    init();
    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }

    //dp
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            int minWaste = table[i][j];
            // horizonal cut
            for(int k=1; k<=i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i-k][j]);
            }
            // vertical cut
            //for (int k=1; k<=i; k++){ //Sua k<=i thanh k<=j
            for (int k=1; k<=j; k++) {	//Vi day la cat theo cot cua hinh chu nhat
                minWaste = min(minWaste, table[i][k] + table[i][j-k]);
            }
            table[i][j] = minWaste;
        }
    }

    cout << table[h][w] << endl;
} //Cao Viet Anh 20215299
