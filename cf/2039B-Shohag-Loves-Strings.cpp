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

void findSubstr(const string s)
{
    unordered_set<string> count;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= int(s.length()) - i; j++)
        {
            count.insert(s.substr(i, j));
        }
    }
    cout << count.size() << endl;
}
int main()
{
    int t;
    cin >> t;
    vector<string> results;
    for (int _ = 0; _ < t; _++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            string p = s.substr(j, 1);
            if (j + 1 < s.length())
            {
                if (s[j + 1] == s[j])
                {
                    p += s[j];
                    results.push_back(p);
                    break;
                }
                p += s[j + 1];
            }
            if (j + 2 < s.length())
            {
                if (s[j + 1] == s[j + 2])
                {
                    p.clear();

                    p = s.substr(j + 1, 2);
                    results.push_back(p);
                    break;
                }
                else if (s[j + 2] != s[j])
                {
                    p += s[j + 2];
                    results.push_back(p);
                    break;
                }
            }
        }
        if (results.size() != _ + 1)
            results.push_back("-1");
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}

// abac -> good abaa -> good abab -> bad 7
// abb -> good
// ababab
