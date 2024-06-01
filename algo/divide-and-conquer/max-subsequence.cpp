#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];

int maxSubArraySum(){
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

    int max_sum = maxSubArraySum();
    cout << max_sum;
    return 0;
}
