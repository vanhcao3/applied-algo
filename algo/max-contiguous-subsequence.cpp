#include <bits/stdc++.h>
using namespace std;

int largest_even_subsequence(int n, vector<int>& sequence) {
    int sum_positive = INT_MIN;
    int sum_negative = INT_MIN;
    bool has_positive = false;
    bool has_negative = false;
    
    for (int num : sequence) {
        if (num > 0) {
            has_positive = true;
            if (sum_positive == INT_MIN) {
                sum_positive = num;
            } else {
                sum_positive += num;
            }
        } else if (num < 0) {
            has_negative = true;
            if (sum_negative == INT_MIN) {
                sum_negative = num;
            } else {
                sum_negative = max(sum_negative, num);
            }
        }
    }

    if (!has_negative) {
        if (sum_positive % 2 == 0) {
            return sum_positive;
        } else {
            return -1; // NOT_FOUND
        }
    }
    
    int total_sum = sum_positive;
    if (sum_positive % 2 == 0) {
        return max(total_sum, sum_positive + sum_negative);
    } else {
        return max(sum_positive - abs(sum_negative), max(total_sum, sum_positive + sum_negative));
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
    int result = largest_even_subsequence(n, sequence);
    if (result == -1) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
