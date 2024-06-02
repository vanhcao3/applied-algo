#include <bits/stdc++.h>
using namespace std;
//Cao Viet Anh 20215299
int main(){
    cout << "Cao Viet Anh 20215299\n";
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    int k, t, a; //Khai bao cac bien ben ngoai vong lap
    
    while(n--){
        //int k, t;
        cin >> k >> t;
		//Bo tri lai cau lenh dieu kien de giam thieu phep so sanh
		if(t == 1){ //Neu thon giau
			while(k--){
				//int a;
				cin >> a; 
				sum += a;
				ans = max(ans, -sum);
			}
		}
		else if(t == -1){//Neu thon ngheo
			while(k--){
				//int a;
				cin >> a; 
				sum -= a;
				ans = max(ans, -sum);
			}
		}
    }
    cout << "Phai tu mang theo: " << ans;
}

