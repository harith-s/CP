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
    long long m;
    long long a;
    long long b;
    long long c;
    cin >> m;
    cin >> a;
    cin >> b;
    cin >> c;
    long long ans = 0;
    ans = min(m , a);
    ans += min(m, b);
    ans += c;
    ans = min(ans, 2 * m);
    results.push_back(ans);
  }
  for (int i = 0; i < results.size(); i++)
  {
    cout << results[i] << endl;
  }
}
