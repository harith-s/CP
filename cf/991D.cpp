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

int main(){
    int num_testcases;
    cin >> num_testcases;
    vector<string> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++){
            while (i > 0 and s[i] - 1 > s[i - 1]){
                char t = s[i - 1];
                s[i - 1] = s[i] - 1;
                s[i] = t;
                i--;
            }
        }
        results.push_back(s);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}
