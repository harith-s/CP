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

int findMin(int i, int j, int k, int count, string &a, string &b, string &c)
{
    if (k == c.length())
        return count;

    if (i < a.length() && c[k] == a[i])
        return min(findMin(i + 1, j, k + 1, count, a, b, c), findMin(i, j + 1, k + 1, count + 1, a, b, c));
    else if (j < b.length() && c[k] == b[j])
        return min(findMin(i, j + 1, k + 1, count, a, b, c), findMin(i + 1, j, k + 1, count + 1, a, b, c));
    else
        return min(findMin(i + 1, j, k + 1, count + 1, a, b, c), findMin(i, j + 1, k + 1, count + 1, a, b, c));
}
int main()
{
    int num_testcases;
    cin >> num_testcases;
    vector<int> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
        string a;
        string b;
        string c;
        cin >> a;
        cin >> b;
        cin >> c;

        int min = findMin(0, 0, 0, 0, a, b, c);
        results.push_back(min);
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}
