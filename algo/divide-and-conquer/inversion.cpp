#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    vector<int> left(leftSize);
    vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < rightSize; j++)
        right[j] = arr[mid + 1 + j];

    long long inversions = 0;
    int i = 0, j = 0, k = low;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += leftSize - i;
        }
    }

    while (i < leftSize)
        arr[k++] = left[i++];

    while (j < rightSize)
        arr[k++] = right[j++];

    return inversions % 1000000007;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high) {
    long long inversions = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;

        inversions += mergeSortAndCount(arr, low, mid);
        inversions += mergeSortAndCount(arr, mid + 1, high);

        inversions += merge(arr, low, mid, high);
    }
    return inversions % 1000000007;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count = mergeSortAndCount(a, 0, n - 1);

    cout << count << endl;

    return 0;
}

