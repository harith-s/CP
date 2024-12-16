#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> buildAdj(vector<vector<int>> &times, int n)
{
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto edge : times)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    return adjList;
}

void dijkstra(int s, vector<int> &sp, vector<vector<int>> &times, int n)
{
    auto adjList = buildAdj(times, n);
    set<pair<int, int>> visit;
    visit.insert({0, s});
    sp[s] = 0;
    while (visit.empty() == false)
    {
        int vertex = visit.begin()->second;
        visit.erase(visit.begin());

        for (auto adj : adjList[vertex])
        {
            int w = adj.first;
            int len = adj.second;

            if (sp[vertex] + len < sp[w])
            {
                visit.erase({sp[w], w});
                sp[w] = sp[vertex] + len;
                visit.insert({sp[w], w});
            }
        }
    }
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<int> sp(n + 1, INT_MAX);
    sp[0] = -1;
    dijkstra(k, sp, times, n);

    int max = 0;

    for (auto dist : sp)
    {
        if (max < dist)
            max = dist;
        if (dist == INT_MAX)
        {
            max = -1;
            break;
        }
    }
    return max;
}

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << networkDelayTime(times, n, k);
}
