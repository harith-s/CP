#include <bits/stdc++.h>
  #include <vector>
  #include <string>

using namespace std;

int main(){
    int num_testcases;
    cin >> num_testcases;
    vector<long long> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
      long long n; cin >> n;
      results.push_back(n - 1);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}
