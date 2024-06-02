#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assign_reviewers(int N, int M, int b, vector<vector<int>>& papers) {
    // Initialize a vector to store the load of each reviewer
    vector<int> reviewer_load(M, 0);

    // Sort the papers based on the number of reviewers willing to review them
    sort(papers.begin(), papers.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });

    // Iterate over each paper
    for (auto& paper : papers) {
        // Sort the reviewers based on their current load
        sort(paper.begin(), paper.end(), [&reviewer_load](int a, int b) {
            return reviewer_load[a - 1] < reviewer_load[b - 1];
        });

        // Assign the paper to the b least loaded reviewers
        for (int i = 0; i < b; ++i) {
            int reviewer = paper[i];
            paper[i] = reviewer;
            reviewer_load[reviewer - 1]++;
        }
    }

    // Calculate the maximum load among reviewers
    int max_load = *max_element(reviewer_load.begin(), reviewer_load.end());

    // Check if all papers have been assigned b reviewers
    for (auto& paper : papers) {
        if (paper.size() != b) {
            return -1;
        }
    }

    return max_load;
}

int main() {
    int N, M, b;
    cin >> N >> M >> b;
    vector<vector<int>> papers(N);
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        papers[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> papers[i][j];
        }
    }
    cout << assign_reviewers(N, M, b, papers) << endl;
    return 0;
}
