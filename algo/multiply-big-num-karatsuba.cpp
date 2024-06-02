#include <bits/stdc++.h>
using namespace std;

// Function to add two strings representing large integers
string add(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int i = n1 - 1, j = n2 - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result += to_string(sum % 10);
        carry = sum / 10;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// Function to multiply two strings representing large integers using Karatsuba algorithm


// Function to subtract two strings representing large integers
string subtract(const string& num1, const string& num2) {
    string result;
    int borrow = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int i = n1 - 1, j = n2 - 1;
    
    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += to_string(diff);
    }
    
    // Remove leading zeros
    while (!result.empty() && result.back() == '0') {
        result.pop_back();
    }
    
    reverse(result.begin(), result.end());
    
    // If the result is empty, it means it's zero
    if (result.empty()) {
        return "0";
    }
    
    return result;
}

string karatsuba(const string& x, const string& y) {
    int n = max(x.size(), y.size());
    
    if (n == 1) {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }
    
    int half_n = n / 2;
    string high1 = (x.size() > half_n) ? x.substr(0, x.size() - half_n) : "0";
    string low1 = (x.size() > half_n) ? x.substr(x.size() - half_n) : x;
    string high2 = (y.size() > half_n) ? y.substr(0, y.size() - half_n) : "0";
    string low2 = (y.size() > half_n) ? y.substr(y.size() - half_n) : y;
    
    string z0 = karatsuba(low1, low2);
    string z1 = karatsuba(add(low1, high1), add(low2, high2));
    string z2 = karatsuba(high1, high2);
    
    string result1 = z2 + string(2 * half_n, '0');
    string result2 = subtract(subtract(z1, z2), z0) + string(half_n, '0');
    string result3 = z0;
    
    return add(add(result1, result2), result3);
}

int main() {
    string a, b;
    cin >> a >> b;

    // In ra kết quả
    cout << karatsuba(a, b) << endl;

    return 0;
}
