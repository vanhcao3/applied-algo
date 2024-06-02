#include <bits/stdc++.h>
using namespace std;

bool canDivide(const vector<int>& arr, int n, int m, long long maxWeight) {
    long long currentSum = 0;
    int requiredSubsequences = 1;

    for (int i = 0; i < n; ++i) {
        if (currentSum + arr[i] > maxWeight) {
            ++requiredSubsequences;
            currentSum = arr[i];
            if (requiredSubsequences > m) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long left = *max_element(arr.begin(), arr.end());
    long long right = accumulate(arr.begin(), arr.end(), 0LL);
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canDivide(arr, n, m, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
