#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;

int main()
{
  int num_testcases;
  cin >> num_testcases;
  vector<long long> results;
  for (int _ = 0; _ < num_testcases; _++)
  {


    long long k;
    long long l1;
    long long l2;
    long long r1;
    long long r2;
    cin >> k;
    cin >> l1;
    cin >> r1;
    cin >> l2;
    cin >> r2;
    long long count = 0;
    unordered_map<int, long long> hashmap;
    int max_power = 0;
    int min_power = 0;
    long long t = 1;
    for (int n = 0; t <= 1000000000 * k && t > 0; n++)
    {
      hashmap[n] = t;
      t = t * k;
    }
    
    for (min_power = 0; l1 * hashmap[min_power] < l2; min_power++)
        ;

    while (l1 * hashmap[max_power] <= r2)
    {

      max_power++;
    }

    for (int x = l1; x <= r1; x++)
    {
      if (x * hashmap[max_power] > r2)
        max_power--;
      if (min_power - 1 >= 0 && x * hashmap[min_power - 1] >= l2)
        min_power--;
      count += max_power - min_power + (max_power > min_power ? 1 : 0);
      cout << max_power << " " <<min_power  << endl;
    }
    results.push_back(count);
  }
  for (int i = 0; i < results.size(); i++)
  {
    cout << results[i] << endl;
  }
}


