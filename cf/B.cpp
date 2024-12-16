#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int num_testcases;
  cin >> num_testcases;
  vector<int> results;
  for (int _ = 0; _ < num_testcases; _++)
  {
    int n;
    cin >> n;
    int r = 4;
    int l = 1;
    int count = n > 1 ? 2 : 1;
    int num_ones = 1;
    while (r < n)
    {
      num_ones += r - num_ones;
      r = 2 * (num_ones + 1);
      count++;
    }
    results.push_back(count);
  }
  for (int i = 0; i < results.size(); i++)
  {
    cout << results[i] << endl;
  }
}
