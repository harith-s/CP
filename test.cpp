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

class Compare
{
    public:
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0] > b[0];
    }
};

int main(){
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    pq.push({10,1,2,3,4});
    pq.push({3,1,4,3,4});
    pq.push({5,1,3,3,4});
    pq.push({1,1,5,3,4});

    while (pq.empty() == false)
    {
        for (auto e : pq.top()){
            cout << e << ", ";
        }
        cout << endl;
        pq.pop();
    }

}
