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
    vector<vector<int>> results;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        bool sorted = true;

        auto a_sorted = a;
        sort(a_sorted.begin(), a_sorted.end());
        
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
                sorted = false;
        }

        while (not(sorted))
        {
            sorted = true;
            int index = 0;

            for (int j = 0; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[j] > a[k])
                    {
                        if (sorted == true || a[index] > a[j])
                            index = j;
                        sorted = false;
                        break;
                    }
                }
            }
            if (not(sorted))
            {
                int temp = a[index];
                a.erase(a.begin() + index);
                a.push_back(temp + 1);
            }
        }
        results.push_back(a);
    }
    for (int i = 0; i < results.size(); i++)
    {
        for (auto integer : results[i])
        {
            cout << integer << " ";
        }
        cout << endl;
    }
}


set<