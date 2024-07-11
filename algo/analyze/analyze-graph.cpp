#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Graph representation using adjacency list
class Graph
{
public:
    unordered_map<string, unordered_set<string>> adjList;
    unordered_map<string, pair<int, int>> points;

    void addPoint(const string &pointID, int x, int y)
    {
        points[pointID] = {x, y};
        adjList[pointID]; // Ensure the point exists in the adjacency list even if it has no edges
    }

    void addSegment(const string &pointID1, const string &pointID2)
    {
        adjList[pointID1].insert(pointID2);
        adjList[pointID2].insert(pointID1);
    }

    int numberPoints() const
    {
        return points.size();
    }

    int numberSegments() const
    {
        int count = 0;
        for (const auto &pair : adjList)
        {
            count += pair.second.size();
        }
        return count / 2; // Each edge is counted twice
    }

    int connectedComponents()
    {
        unordered_set<string> visited;
        int components = 0;

        for (const auto &pair : points)
        {
            if (visited.find(pair.first) == visited.end())
            {
                dfs(pair.first, visited);
                components++;
            }
        }

        return components;
    }

    int longestCycleFrom(const string &start)
    {
        int maxLength = 0;
        unordered_set<string> visited;
        dfsCycle(start, start, visited, 1, maxLength);
        return maxLength;
    }

private:
    void dfs(const string &pointID, unordered_set<string> &visited)
    {
        visited.insert(pointID);
        for (const auto &neighbor : adjList[pointID])
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfs(neighbor, visited);
            }
        }
    }

    void dfsCycle(const string &start, const string &current, unordered_set<string> &visited, int length, int &maxLength)
    {
        visited.insert(current);
        for (const auto &neighbor : adjList[current])
        {
            if (neighbor == start && length >= 3)
            { // Valid cycle must have at least 3 edges
                maxLength = max(maxLength, length);
                return;
            }
            if (visited.find(neighbor) == visited.end())
            {
                dfsCycle(start, neighbor, visited, length + 1, maxLength);
                visited.erase(neighbor); // Backtrack
            }
        }
    }
};

int main()
{
    Graph graph;
    string line;

    // Read points
    while (getline(cin, line) && line != "#")
    {
        stringstream ss(line);
        string pointID;
        int x, y;
        ss >> pointID >> x >> y;
        graph.addPoint(pointID, x, y);
    }

    // Read segments
    while (getline(cin, line) && line != "#")
    {
        stringstream ss(line);
        string segmentID, pointID1, pointID2;
        ss >> segmentID >> pointID1 >> pointID2;
        graph.addSegment(pointID1, pointID2);
    }

    // Process queries
    while (getline(cin, line) && line != "###")
    {
        stringstream ss(line);
        string query, pointID;

        ss >> query >> pointID;
        if (query == "?number_points")
        {
            cout << graph.numberPoints() << endl;
        }
        else if (query == "?number_segments")
        {
            cout << graph.numberSegments() << endl;
        }
        else if (query == "?connected_components")
        {
            cout << graph.connectedComponents() << endl;
        }
        else if (query == "?longest_cycle_from")
        {
            cout << graph.longestCycleFrom(pointID) << endl;
        }
    }

    return 0;
}