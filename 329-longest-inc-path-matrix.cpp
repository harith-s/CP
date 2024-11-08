#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
using namespace std;

map<pair<int, int>, vector<pair<int, int>>> createGraph(int m, int n)
{
    map<pair<int, int>, vector<pair<int, int>>> adjList;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row > 0)
                adjList[{row, col}].push_back({row - 1, col});
            if (col > 0)
                adjList[{row, col}].push_back({row, col - 1});
            if (row < m - 1)
                adjList[{row, col}].push_back({row + 1, col});
            if (col < n - 1)
                adjList[{row, col}].push_back({row, col + 1});
        }
    }
    return adjList;
}


int dfs(pair<int, int> node, vector<vector<int>> &matrix, map<pair<int, int>, int> &lookup_table)
{
    int row = node.first;
    int col = node.second;

    int num_rows = matrix.size();
    int num_cols = matrix[0].size();
    stack<pair<int, int>> visit;
    stack<int> level;

    visit.push({row, col});
    level.push(0);
    int max_level = 0;

    set<pair<int, int>> to_update;
    vector<pair<int, int>> adj;

    while (visit.empty() == false)
    {
        pair<int, int> cur_node = visit.top();
        int path_length = level.top();
        max_level = max(max_level, path_length);

        level.pop();
        visit.pop();

        adj = findValidAdj(cur_node.first, cur_node.second, matrix);

        if (to_update.find(cur_node) == to_update.end())
        {
            to_update.insert(cur_node);
            lookup_table[cur_node] = 0;
        }
        for (auto neighbor : adj)
        {
            visit.push(neighbor);
            level.push(path_length + 1);
        }
    }

    return max_level;
}

int dfsREC(pair<int, int> node, vector<vector<int>> &matrix, map<pair<int, int>, int> &lookup_table, int path_length, int prev_pl)
{
    // if (lookup_table.find(node) != lookup_table.end())
    //     return lookup_table[node] - 1 + path_length;

    vector<pair<int, int>> adj_nodes = findValidAdj(node.first, node.second, matrix);
    int max_so_far = path_length;

    for (auto adj : adj_nodes)
    {
        int adj_path;

        if (lookup_table.find(adj) == lookup_table.end())
        {
            adj_path = dfsREC(adj, matrix, lookup_table, path_length + 1, path_length);

            // if (path_length == 1)
            //     lookup_table[adj] = adj_path - path_length;
            // else
            //     lookup_table[adj] = 1 + adj_path - path_length;
        }
        else
        {
            adj_path = lookup_table[adj] + path_length;
        }
        max_so_far = max(adj_path, max_so_far);
    }

    lookup_table[node] = max_so_far - prev_pl;
    return max_so_far;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    map<pair<int, int>, int> lookup_table;

    int m = matrix.size();
    int n = matrix[0].size();
    // map<pair<int, int>, vector<pair<int, int>>> adjList = createGraph(m, n);

    int max_plen = 0;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (lookup_table.find({row, col}) == lookup_table.end())
            {
                max_plen = max(dfsREC({row, col}, matrix, lookup_table, 1, 0), max_plen);
                // lookup_table[{row, col}] = max_plen;
            }
            else
                max_plen = max(max_plen, lookup_table[{row, col}]);
        }
    }
    return max_plen;
}

int main()
{
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << longestIncreasingPath(matrix);
}
