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
    string situation;
    cin >> situation;

    char cur = situation[0];
    int count = 0;
    int i;

    for (i = 0; i < situation.length(); i++){
        if (situation[i] == cur) count++;
        else {
            cur = situation[i];
            count = 1;
        }
        if (count >= 7){
            cout << "YES";
            break;
        }
    }
    if (i == situation.length()) cout << "NO";
}
