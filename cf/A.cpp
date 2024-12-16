#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int num_testcases;
  cin >> num_testcases;
  vector<pair<string, int>> results;
  for (int _ = 0; _ < num_testcases; _++)
  {
    int n;
    int k;
    cin >> n;
    cin >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    bool found = true;
    bool push = false;
    for (int i = 0; i < n; i++)
    {
      found = true;
      vector<int> diff(n - 1);
      for (int j = 0; j < n; j++)
      {
        int d = abs(a[i] - a[j]);
        if (i != j && d == k * (d / k))
        {
          found = false;
          break;
        }
      }
      if (found)
      {
        results.push_back({"YES", i + 1});
        push = true;
        break;
      }
    }
    if (push == false)
    {
      results.push_back({"NO", -1});
    }
  }
  for (int i = 0; i < results.size(); i++)
  {
    cout << results[i].first << endl;
    if (results[i].second >= 0)
      cout << results[i].second << endl;
  }
}
