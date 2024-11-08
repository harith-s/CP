#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
        return {0};
    vector<pair<int, int>> graph(n);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        graph[u].first += v;
        graph[v].first += u;

        graph[u].second++;
        graph[v].second++;
    }

    int num_left = n;

    vector<int> curr_leaves;

    for (int node = 0; node < n; node++)
    {
        auto node_info = graph[node];
        if (node_info.second == 1)
        {
            curr_leaves.push_back(node);
        }
    }

    vector<int> next_leaves;

    while (num_left > 2)
    {
        num_left = num_left - curr_leaves.size();
        next_leaves.clear();
        for (auto leaf : curr_leaves)
        {
            int adj = graph[leaf].first;

            graph[leaf].first = 0;
            graph[leaf].second = -1;

            graph[adj].first = graph[adj].first - leaf;
            graph[adj].second--;
            if (graph[adj].second == 1)
            {
                next_leaves.push_back(adj);
            }
        }

        curr_leaves = next_leaves;
    }
    return curr_leaves;
}
vector<set<int>> adjList(const vector<vector<int>> &edges, int num_nodes, vector<int> &degree)
{

    vector<set<int>> adj(num_nodes, set<int>());

    for (auto edge : edges)
    {
        int n1 = edge[0];
        int n2 = edge[1];

        adj[n1].insert(n2);
        adj[n2].insert(n1);

        degree[n1]++;
        degree[n2]++;
    }
    return adj;
}

vector<int> removeLeaves(vector<int> degree, vector<set<int>> &adj, set<int> &nodes_left)
{
    vector<int> new_degree = degree;
    int num_nodes = adj.size();
    for (int i = 0; i < num_nodes; i++)
    {
        if (degree[i] == 1 or degree[i] == 0)
        {
            new_degree[i] = -1;
            int adj_node = *(adj[i].begin());
            adj[i].clear();

            new_degree[adj_node]--;
            adj[adj_node].erase(i);

            nodes_left.erase(i);
        }
    }
    return new_degree;
}

// vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
// {
//     set<int> nodes_left;
//     for (int i = 0; i < n; i++)
//     {
//         nodes_left.insert(i);
//     }
//     vector<int> degree(n, 0);
//     vector<set<int>> adj = adjList(edges, n, degree);

//     vector<int> prev_degree = degree;

//     while (nodes_left.size() > 0)
//     {
//         prev_degree = degree;
//         degree = removeLeaves(degree, adj, nodes_left);
//     }

//     vector<int> result;

//     for (int i = 0; i < n; i++)
//     {
//         if (prev_degree[i] >= 0)
//             result.push_back(i);
//     }
//     return result;
// }

// slow solution
// vector<int> bruteforcefindMinHeightTrees(int n, vector<vector<int>> &edges)
// {
//     vector<vector<int>> adj = adjList(edges, n);
//     map<int, vector<int>> node_hgt_map;

//     int min_hgt = INT32_MAX;

//     for (int node = 0; node < n; node++)
//     {
//         int hgt = bfs(node, adj, min_hgt);
//         min_hgt = min(min_hgt, hgt);
//         if (node_hgt_map.find(hgt) == node_hgt_map.end())
//         {
//             node_hgt_map[hgt] = vector<int>();
//         }
//         node_hgt_map[hgt].push_back(node);
//     }
//     return node_hgt_map[min_hgt];
// }

// vector<vector<int>> adjList(const vector<vector<int>> &edges, int num_nodes, vector<int> & degree)
// {

//     vector<vector<int>> adj(num_nodes, vector<int>());

//     for (auto edge : edges)
//     {
//         int n1 = edge[0];
//         int n2 = edge[1];

//         adj[n1].push_back(n2);
//         adj[n2].push_back(n1);

//         degree[n1]++;
//         degree[n2]++;
//     }
//     return adj;
// }
// int bfs(int n, vector<vector<int>> &adj, int min_hgt)
// {
//     queue<pair<int, int>> to_visit;
//     set<int> visited;

//     int max_level = 0;

//     visited.insert(n);
//     to_visit.push({n, 0});

//     while (to_visit.empty() == false)
//     {
//         int cur_node = to_visit.front().first;
//         int cur_lvl = to_visit.front().second;
//         max_level = max(cur_lvl, max_level);

//         if (max_level > min_hgt)
//             return INT32_MAX;

//         to_visit.pop();

//         for (auto adj_node : adj[cur_node])
//         {
//             if (visited.find(adj_node) == visited.end())
//             {
//                 to_visit.push({adj_node, cur_lvl + 1});
//                 visited.insert(adj_node);
//             }
//         }
//     }
//     return max_level;
// }
int main()
{
    vector<vector<int>> edges = {{1, 0}, {2, 1}, {3, 1}};
    for (auto i : findMinHeightTrees(4, edges))
    {
        cout << i << endl;
    }
}