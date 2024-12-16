#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
  int num_testcases;
  cin >> num_testcases;
  vector<vector<int>> results;
  for (int _ = 0; _ < num_testcases; _++)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    vector<int> ans(n);
    vector<bool> present(n + 1, false);
    int index = 1;
    present[a[0]] = true;
    for (int i = 0; i < n; i++)
    {
      if (present[a[i]] == false)
      {
        present[a[i]] = true;
        ans[i] = a[i];
      }
      else
      {
        while (present[index])
        {
          index++;
        }
        ans[i] = index;
        present[index] = true;
      }
    }
    results.push_back(ans);
  }
  for (int i = 0; i < results.size(); i++)
  {
    for (auto k : results[i])
      cout << k << " ";
    cout << endl;
  }
  
}
