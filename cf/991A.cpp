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
    vector<int> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
        int n;
        int m;
        cin >> n;
        cin >> m;
        vector<string> words(n);
        int count = 0;
        int char_so_far = 0;

        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            char_so_far += word.length();

            if (char_so_far <= m)
                count++;

            words.push_back(word);
        }
        results.push_back(count);
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}
