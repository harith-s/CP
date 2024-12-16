#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

int MSTcost(vector<int> exclude_edge, vector<vector<pair<int, int>>> &adjList, int n)
{
    unordered_set<int> MST;
    int cost = 0;
    vector<int> min_dist(n, INT_MAX);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    min_dist[0] = 0;

    while (MST.size() < n)
    {
        auto [dist, v] = pq.top();
        pq.pop();

        if (visited[v] == false)
        {
            MST.insert(v);
            visited[v] = true;
            cost += dist;

            for (auto item : adjList[v])
            {
                if (exclude_edge[2] == item.second && ((item.first == exclude_edge[0] && v == exclude_edge[1]) || (item.first == exclude_edge[1] && v == exclude_edge[0])))
                    continue;
                int to = item.first;
                int len = item.second;

                if (visited[to] == false)
                {
                    pq.push({len, to});
                }
            }
        }
    }
    return cost;
}

int MSTcost(vector<vector<pair<int, int>>> &adjList, int n, set<pair<pair<int, int>, int>> &pcrit)
{
    unordered_set<int> MST;
    int cost = 0;
    vector<int> min_dist(n, INT_MAX);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    min_dist[0] = 0;

    vector<int> parent(n);

    while (MST.size() < n)
    {
        int dist = pq.top().first;
        int v = pq.top().second;
        pcrit.insert({{parent[v], v}, dist});
        pq.pop();

        vector<pair<int, int>> to_add;

        while (pq.top().first == dist and pq.empty() == false)
        {
            auto [d, v2] = pq.top();
            pcrit.insert({{parent[v2], v2}, d});
            to_add.push_back(pq.top());
            pq.pop();
        }

        while (to_add.empty() == false)
        {
            pq.push(to_add.back());
            to_add.pop_back();
        }

        if (visited[v] == false)
        {
            MST.insert(v);
            visited[v] = true;
            cost += dist;
            int minLen = adjList[v][0].second;
            for (auto item : adjList[v])
            {
                int to = item.first;
                int len = item.second;

                if (visited[to] == false)
                {
                    pq.push({len, to});
                    parent[to] = v;
                }
            }
        }
    }
    return cost;
}

vector<vector<pair<int, int>>> buildAdj(vector<vector<int>> &edges, int n)
{
    vector<vector<pair<int, int>>> adjList(n);
    for (auto edge : edges)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
        adjList[edge[1]].push_back({edge[0], edge[2]});
    }
    return adjList;
}

vector<int> findCritical(int n, vector<vector<int>> &edges)
{
    map<int, int> edge_type;
    set<pair<pair<int, int>, int>> pcrit;

    auto adjList = buildAdj(edges, n);
    int min_cost = MSTcost(adjList, n, pcrit);

    vector<int> pseudocrit;
    for (int i = 0; i < edges.size(); i++)
    {
        auto edge = edges[i];
        pair<pair<int, int>, int> e1 = {{edge[0], edge[1]}, edge[2]};
        pair<pair<int, int>, int> e2 = {{edge[1], edge[0]}, edge[2]};

        if (pcrit.find(e1) != pcrit.end() || pcrit.find(e2) != pcrit.end())
            pseudocrit.push_back(i);
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int cost = MSTcost(edges[i], adjList, n);
        if (cost > min_cost)
            edge_type[i] = 1;
    }
    vector<int> result;
    for (auto item : edge_type)
    {
        if (item.second == 1)
            result.push_back(item.first);
    }
    return result;
}

class UnionFind
{
public:
    vector<int> size;
    vector<int> set;

public:
    UnionFind(int n)
    {
        size.assign(n, 1);
        set.resize(n); // Ensure elements are initialized
        for (int i = 0; i < n; i++)
        {
            set[i] = i; // Each element is its own root initially
        }
    }

    int findSet(int n)
    {
        if (set[n] != n)
            set[n] = findSet(set[n]); // Path compression
        return set[n];
    }

    void combine(int x, int y)
    {
        int sx = findSet(x);
        int sy = findSet(y);

        if (sx == sy)
            return;

        // Union by size
        if (size[sx] < size[sy])
            swap(sx, sy);

        set[sy] = sx;         // Attach smaller tree to larger tree
        size[sx] += size[sy]; // Update size
    }
};

int getMSTcost(vector<vector<int>> &edges, int n, int edge_index, bool include)
{
    // assume edges are sorted
    UnionFind dj(n);
    int cost = 0;
    int num_edges = 0;

    if (include)
    {
        vector<int> sedge = edges[edge_index];
        cost += sedge[2];
        dj.combine(sedge[0], sedge[1]);
        num_edges++;
    }

    for (int i = 0; i < edges.size(); i++)
    {
        auto edge = edges[i];
        if (include == false && edge_index ==i)
            continue;
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dj.findSet(u) != dj.findSet(v))
        {
            dj.combine(u, v);
            cost += w;
            num_edges++;
        }
        if (num_edges == n - 1)
            break;
    }
    return num_edges == n-1 ? cost : INT_MAX;
}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        edges[i].push_back(i);
    }

    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    int mincost = getMSTcost(edges, n, -1, false);
    vector<int> critical;
    vector<int> pcrit;
    for (int i = 0; i < edges.size(); i++)
    {
        if (mincost < getMSTcost(edges, n, i, false))

            critical.push_back(edges[i][3]);
        else if (mincost == getMSTcost(edges, n, i, true))
            pcrit.push_back(edges[i][3]);
    }
    return {critical, pcrit};
}

int main()
{
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}, {2, 3, 4}, {3, 4, 2}, {3, 5, 2}, {4, 5, 2}};
    int n = 5;
    auto result = findCriticalAndPseudoCriticalEdges(n, edges);
    vector<int> critical = result[0];
    vector<int> pcrit = result[1];
    for (auto edge : critical)
    {
        cout << edge << " ";
    }
    cout << endl;
    for (auto edge : pcrit)
    {
        cout << edge << " ";
    }
}
