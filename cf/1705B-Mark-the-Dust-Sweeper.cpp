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
    vector<long long> results;
    for (int i = 0; i < num_testcases; i++)
    {
        int nrooms;
        cin >> nrooms;
        long long tot_op = 0;
        int dust;
        bool found_non_zero = false;

        for (int j = 0; j < nrooms; j++)
        {
            cin >> dust;
            if (dust > 0)
                found_non_zero = true;
            else if (found_non_zero and dust == 0 and j != nrooms - 1)
                tot_op++;

            if (j != nrooms - 1)
                tot_op += dust;
        }
        results.push_back(tot_op);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}

