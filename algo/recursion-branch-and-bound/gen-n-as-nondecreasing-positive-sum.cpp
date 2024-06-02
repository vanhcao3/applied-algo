#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(vector<int>& combination, int k, int n, int start) {
    if (k == 0 && n == 0) {
        for (int i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i != combination.size() - 1) cout << " ";
        }
        cout << endl;
        return;
    }
    if (k == 0 || n == 0 || start > n) return;

    for (int i = start; i <= n; ++i) {
        combination.push_back(i);
        generateCombinations(combination, k - 1, n - i, i);
        combination.pop_back();
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    
    vector<int> combination;
    generateCombinations(combination, k, n, 1);

    return 0;
}
