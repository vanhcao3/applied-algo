#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to check if the route is feasible with the given precedence constraints
bool isFeasibleRoute(const vector<int> &route, const vector<pair<int, int>> &constraints)
{
    unordered_map<int, int> position;
    for (int i = 0; i < route.size(); ++i)
    {
        position[route[i]] = i;
    }
    for (const auto &constraint : constraints)
    {
        if (position[constraint.first] > position[constraint.second])
        {
            return false;
        }
    }
    return true;
}

// Function to calculate the total travel distance of the route
int calculateTravelDistance(const vector<int> &route, const vector<vector<int>> &distanceMatrix)
{
    int totalDistance = 0;
    for (int i = 0; i < (int)route.size() - 1; ++i)
    {
        totalDistance += distanceMatrix[route[i] - 1][route[i + 1] - 1];
    }
    // Adding distance from last point back to the first point
    totalDistance += distanceMatrix[route.back() - 1][route[0] - 1];
    return totalDistance;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> route(n);
    for (int &x : route)
        cin >> x;

    vector<vector<int>> distanceMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> distanceMatrix[i][j];
        }
    }

    cin >> m;
    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> constraints[i].first >> constraints[i].second;
    }

    if (!isFeasibleRoute(route, constraints))
    {
        cout << -1 << endl;
    }
    else
    {
        cout << calculateTravelDistance(route, distanceMatrix) << endl;
    }

    return 0;
}