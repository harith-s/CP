#include <bits/stdc++.h>
using namespace std;

int gcd(set<int> work)
{
    if (work.size() == 0)
        return 0;
    auto it1 = work.begin();
    if (work.size() == 1) return *it1;
    auto it2 = it1++;

    int g = gcd(*it1, *it2);
    if (g == 1) return g;
    for (auto it = it2++; it != work.end(); it++)
    {
        g = gcd(g, *it);
        if (g == 1)
            return 1;
    }
    return g;
}

int main()
{
    int num_testcases;
    cin >> num_testcases;
    vector<vector<int>> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
        int n;
        int q;
        cin >> n;
        cin >> q;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> ans;

        for (int i = 0; i < q; i++)
        {
            set<int> work;
            int l;
            int r;
            cin >> l;
            cin >> r;
            for (int j = l - 1; j < r; j++)
            {
                for (int k = j + 1; k < r; k++)
                {
                    if (a[j] - a[k] != 0)
                        work.insert(abs(a[j] - a[k]));
                }
            }
            ans.push_back(gcd(work));
        }
        results.push_back(ans);
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


