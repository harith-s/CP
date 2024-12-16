#include <bits/stdc++.h>
  #include <vector>
  #include <string>

using namespace std;

int main(){
    int num_testcases;
    cin >> num_testcases;
    vector<string> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
      string s; cin >> s;
      string result = "";

      for (int i = int(s.length()) - 1; i >= 0; i--){
        if (s[i] == 'p') result += 'q';
        else if (s[i] == 'q') result += 'p';
        else result += 'w';
      }
      results.push_back(result);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}
