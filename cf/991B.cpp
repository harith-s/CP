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
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        long long odd_sum = 0;
        long long odd_count = 0;
        long long even_sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (i % 2 == 0)
            {
                odd_sum += a[i];
                odd_count++;
            }
            else
                even_sum += a[i];
        }
        if (sum - n * (sum / n) != 0)
        {
            results.push_back("NO");
            continue;
        }
        long long target = sum / n;
        if (odd_count * target != odd_sum)
            results.push_back("NO");
        else
            results.push_back("YES");
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}
