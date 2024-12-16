#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <math.h>
using namespace std;


set<int> findPrimes(int n){
    set<int> r;
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++){
        if (prime[p]){
            for (int i = p * p; i <= n; i+= p){
                prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (prime[i]) r.insert(i);
    }
    return r;
}
int main()
{
    int t;
    cin >> t;
    vector<vector<int>> results;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        auto primes = findPrimes(2 * n);
        vector<int> even;
        vector<int> odd;
        for (int j = 1; j <= n; j++)
        {
            if (j - 2 * (j / 2) == 0)
                even.push_back(j);
            else
                odd.push_back(j);
        }
        int n1 = -1;
        int n2 = -1;
        bool found = false;
        for (auto e : even)
        {
            for (auto o : odd)
            {
                if (primes.find(e + o) == primes.end())
                {
                    n1 = e;
                    n2 = o;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found)
        {
            results.push_back(vector<int>(1, -1));
        }
        else
        {
            vector<int> result;
            for (auto e : even)
            {
                if (e != n1)
                    result.push_back(e);
            }
            result.push_back(n1);
            result.push_back(n2);
            for (auto o : odd)
            {
                if (o != n2)
                    result.push_back(o);
            }
            results.push_back(result);
            

        }
    }
    for (int i = 0; i < results.size(); i++)
    {
        for (auto integer : results[i])
        {
            cout << integer << " ";
        }
        cout << endl;
    }
}
