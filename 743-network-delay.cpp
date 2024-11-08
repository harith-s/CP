#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> buildAdj(vector<vector<int>> &times, int n)
{
    vector<vector<pair<int, int>>> adjList(n);
    for (auto edge : times)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    return adjList;
}

int findMin(map<int,int> & u){
    pair<int,int> min = *u.begin();

    for (auto item : u){
        if (item.second < min.second){
            min = item;
        }
    }
    return min.first;


}


int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    
}


int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout << networkDelayTime(times, n, k);
}
