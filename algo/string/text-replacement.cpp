#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main() {
    string p1, p2, text;
    string word;
    stringstream output;
    output.clear();
    
    getline(cin, p1);
    getline(cin, p2);
    
    while(getline(cin, text)){
		stringstream ss(text);
        while(ss >> word){
			if(word.compare(p1) == 0)
				cout << p2 << ' ';
			else cout << word << ' ';
		}		
    }
    return 0;
}
