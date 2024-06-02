#include <iostream>
using namespace std;
#include <string.h>
#include <stack>
//Cao Viet Anh 20215299 
int par(string str){
    int a = str.length();
    stack<char> S;
    //char x, y; //Bien cuc bo y bi thua
    char x; //Bo bien y
    for (int i=0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
			//Them: Kiem tra ngan xep rong truoc khi lay phan tu trong Stack ra
			if(S.empty()) //Neu khong phai dau mo ngoac ma ngan xep rong tuc la sai
				return 0; //lap tuc tra ve 0
			
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    //S.top() dung de lay phan tu dau Stack, khong bao gio = NULL
    //if (S.top() != NULL){
    if (!S.empty()){ //Sua thanh "!S.empty()" tra ve 0 neu S khac rong
        return 0;
    }
    else return 1;
}
 
int main(){
    string str;
    getline(cin, str);
    cout << par(str);
    return 0;
} //Cao Viet Anh 20215299
