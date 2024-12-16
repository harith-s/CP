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
    vector<string> results;
    for (int i = 0; i < t; i++)
    {
        int len;
        cin >> len;
        string s;
        cin >> s;
        map<char, int> hashmap;

        int imin = 0;
        int imax = 0;

        for (int j = 0; j < s.length(); j++)
        {
            char c = s[j];
            if (hashmap.find(c) == hashmap.end())
            {
                hashmap[c] = 1;
            }
            else
            {
                hashmap[c]++;
                if (hashmap[c] > hashmap[s[imax]])
                    imax = j;
            }
        }
        char minc = s[0];
        for (auto item : hashmap){
            if (item.second < hashmap[minc] || (item.second == hashmap[minc] and minc == s[imax])) minc = item.first;
        }
        imin = s.find(minc);
        s[imin] = s[imax];
        results.push_back(s);
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}
