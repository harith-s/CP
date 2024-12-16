#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

class UnionFind
{
    map<pair<int, int>, int> ids;

    vector<int> parent;
    vector<int> size;

public:
    UnionFind(vector<vector<int>> &points)
    {
        int sz = points.size();
        parent.reserve(sz);
        size.reserve(sz);
        for (int i = 0; i < sz; i++)
        {
            ids[{points[i][0], points[i][1]}] = i;
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findID(pair<int, int> point)
    {
        return ids[point];
    }
    int findParent(int id)
    {
        if (parent[id] != id)
            parent[id] = findParent(parent[id]);
        return parent[id];
    }
    void combine(int id1, int id2)
    {
        int parent1 = findParent(id1);
        int parent2 = findParent(id2);

        if (parent1 == parent2)
            return;

        if (size[parent1] < size[parent2])
            swap(parent1, parent2);

        parent[parent2] = parent1;
        size[parent1] += size[parent2];
    }
};
class Compare
{
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0] > b[0];
    }
};

int manhattanDist(const vector<int> &p1, const vector<int> &p2)
{
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<int> sp(n, 2147483647);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    sp[0] = 0;

    set<int> MST;
    int cost = 0;
    while (MST.size() < n)
    {
        auto [dist, id] = pq.top();
        pq.pop();

        if (MST.find(id) == MST.end())
        {
            MST.insert(id);
            cost += dist;

            for (int v = 0; v < n; v++)
            {
                if (MST.find(v) == MST.end())
                {
                    int newDist = manhattanDist(points[id], points[v]);
                    
                    if (newDist < sp[v])
                    {
                        sp[v] = newDist;
                        pq.push({newDist, v});
                        
                    }
                }
            }
        }
    }
    return cost;
}
int main()
{
    vector<vector<int>> points = {{-8, 14}, {16, -18}, {-19, -13}, {-18, 19}, {20, 20}, {13, -20}, {-15, 9}, {-4, -8}};
    cout << minCostConnectPoints(points);
}
