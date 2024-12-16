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
    int num_testcases;
    cin >> num_testcases;
    vector<string> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
        string s;
        cin >> s;
        int sum = 0;
        unordered_map<char, int> umap;
        for (auto c : s)
        {
            if (umap.count(c))
                umap[c]++;
            else
                umap[c] = 1;
            string temp = "";
            temp += c;
            sum += stoi(temp);
        }
        int rem = sum % 9;

        if (rem == 0)
        {
            results.push_back("YES");
        }

        // 2 adds 2 and 3 adds 6
        else if (rem == 1)
        {
            if ((umap['2'] > 0 && umap['3'] > 0) || umap['2'] >= 4)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
        else if (rem == 2)
        {
            if (umap['2'] >= 8 || umap['3'] >= 1 && umap['2'] >= 5 || umap['3'] >= 2 && umap['2'] >= 2)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
        else if (rem == 3)
        {
            if (umap['3'] > 0 || umap['2'] >= 3)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
        else if (rem == 4)
        {
            if (umap['2'] >= 7 || umap['3'] >= 1 && umap['2'] >= 4 || umap['3'] >= 2 && umap['2'] >= 1)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
        else if (rem == 5)
        {
            if (umap['2'] >= 2)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
        else if (rem == 6)
        {
            if (umap['2'] >= 6 || umap['3'] >= 1 && umap['2'] >= 3 || umap['3'] >= 2)
                results.push_back("YES");
            else
                results.push_back("NO");
        }

        else if (rem == 7)
        {
            if (umap['2'] >= 1)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
        else if (rem == 8)
        {
            if (umap['2'] >= 5 || umap['3'] >= 1 && umap['2'] >= 2)
                results.push_back("YES");
            else
                results.push_back("NO");
        }
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}
