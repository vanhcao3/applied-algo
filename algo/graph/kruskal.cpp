#include <bits/stdc++.h>
using namespace std;

bool comparator(const tuple<int, int, int> &edge1, const tuple<int, int, int> &edge2)
{
    if (get<2>(edge1) == get<2>(edge2))
    {
        if (get<1>(edge1) == get<1>(edge2))
        {
            return get<0>(edge1) < get<0>(edge2);
        }
        else
            return get<1>(edge1) < get<1>(edge2);
    }
    else
        return get<2>(edge1) < get<2>(edge2);
}

int find(int x, vector<int> &link)
{
    while (x != link[x])
        x = link[x];
    return x;
}

bool same(int a, int b, vector<int> &link)
{
    return find(a, link) == find(b, link);
}

void unite(int a, int b, vector<int> &size, vector<int> &link)
{
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b])
        swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int main()
{
    int m, n, u, v, w, minimum_spanning_tree = 0;
    cin >> n >> m;

    vector<tuple<int, int, int>> tree;
    vector<int> link(n + 1), size(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        tree.push_back(make_tuple(u, v, w));
    }

    for (int i = 1; i <= n; i++)
    {
        link[i] = i;
        size[i] = 1;
    }

    sort(tree.begin(), tree.end(), comparator);

    for (auto edge : tree)
    {
        int node1 = get<0>(edge);
        int node2 = get<1>(edge);
        if (!same(node1, node2, link))
        {
            unite(node1, node2, size, link);
            minimum_spanning_tree += get<2>(edge);
        }
    }

    cout << minimum_spanning_tree << endl;

    return 0;
}
