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
    int n; cin >> n;
    if (n != 2 && n - 2*(n / 2) == 0) cout << "YES\n";
    else cout << "NO\n";
}
