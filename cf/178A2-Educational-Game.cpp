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

bool isSquare(long long tiles){
    if (tiles % 2 == 0) return false;
    long long rt = sqrt(tiles);
    if (rt * rt == tiles) return true;
    return false;
}
int main(){
    int t; cin >> t;
    vector<long long> results;

    for (int i = 0; i < t; i++){
        int n; cin >> n;
        long long happy = 0;
        long long tiles = 0;

        for (int day = 0; day < n; day++){
            int k; cin >> k;
            tiles += k;
            if (isSquare(tiles)) happy+=1;
            

        }
        
        results.push_back(happy);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}
