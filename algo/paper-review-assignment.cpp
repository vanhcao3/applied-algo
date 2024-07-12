#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assign_reviewers(int N, int M, int b, vector<vector<int>> &papers)
{
    vector<int> reviewer_load(M, 0); // Step 2: Initialize reviewer load

    // Step 3: Sort papers based on the number of willing reviewers
    sort(papers.begin(), papers.end(), [](const vector<int> &a, const vector<int> &b)
         { return a.size() < b.size(); });

    for (auto &paper : papers)
    { // Step 4: Assignment Algorithm
        sort(paper.begin(), paper.end(), [&reviewer_load](int a, int b)
             { return reviewer_load[a - 1] < reviewer_load[b - 1]; });

        if (paper.size() < b)
            return -1; // Not enough reviewers

        for (int i = 0; i < b; ++i)
        { // Assign b reviewers
            reviewer_load[paper[i] - 1]++;
        }
    }

    // Step 5: Calculate Maximum Load
    int max_load = *max_element(reviewer_load.begin(), reviewer_load.end());

    return max_load; // Step 6: Output
}

int main()
{
    int N, M, b;
    cin >> N >> M >> b;
    vector<vector<int>> papers(N);
    for (int i = 0; i < N; ++i)
    {
        int k;
        cin >> k;
        papers[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> papers[i][j];
        }
    }

    int result = assign_reviewers(N, M, b, papers);
    if (result == -1)
        cout << "-1\n";
    else
        cout << result << "\n";

    return 0;
}