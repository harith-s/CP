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

int main()
{
    int t;
    cin >> t;
    vector<long long> results;

    for (int i = 0; i < t; i++)
    {
        int cols;
        cin >> cols;
        vector<vector<long long>> matrix(2);
        for (int i = 0; i < cols; i++)
        {
            int n;
            cin >> n;
            matrix[0].push_back(n);
        }
        for (int i = 0; i < cols; i++)
        {
            int n;
            cin >> n;
            matrix[1].push_back(n);
        }
        long long max_cost = INT_MIN;
        long long max_bottom = INT_MIN;
        long long cost = 0;
        int count = 0;

        vector<int> max_ones(cols);
        for (int col = 0; col < cols; col++)
        {
            if (matrix[0][col] <= matrix[1][col])
            {
                max_ones[col] = matrix[1][col];
                max_cost = max_cost == INT_MIN ? matrix[0][col] : max(max_cost, matrix[0][col]);
            }
            else
            {
                max_ones[col] = matrix[0][col];
                max_cost = max_cost == INT_MIN ? matrix[1][col] : max(max_cost, matrix[1][col]);
            }
            cost += max_ones[col];
        }
        if (max_cost != INT_MIN)
            cost += max_cost;
        else{
            cost += max_bottom;
        }
        results.push_back(cost);
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}
