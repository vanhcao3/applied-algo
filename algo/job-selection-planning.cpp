#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareJobs(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int jobSelection(int n, vector<pair<int, int>>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs); // Sort jobs by profit in descending order
    
    vector<bool> selectedJobs(100001, false); // Assuming maximum possible deadline is 100000
    int totalProfit = 0;
    
    for (int i = 0; i < n; ++i) {
        int deadline = jobs[i].first;
        int profit = jobs[i].second;
        
        // Find the latest available deadline for this job
        while (deadline > 0 && selectedJobs[deadline]) {
            --deadline;
        }
        
        // If there's an available slot, select the job and update profit
        if (deadline > 0) {
            selectedJobs[deadline] = true;
            totalProfit += profit;
        }
    }
    
    return totalProfit;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> jobs(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].first >> jobs[i].second;
    }
    
    cout << jobSelection(n, jobs) << endl;
    
    return 0;
}

