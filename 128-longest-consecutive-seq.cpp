// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Element
{
    int node;
    int parent;
    int size;
    Element(int n)
    {
        node = n;
        parent = n;
        size = 1;
    }
};

class UnionFind
{
    map<int, Element *> mapping;

public:
    bool present(int x)
    {
        return mapping.find(x) != mapping.end();
    }
    UnionFind(vector<int> nodes)
    {
        for (auto node : nodes)
        {
            Element *e = new Element(node);
            mapping[node] = e;
        }
    }
    int findSet(int x)
    {
        int &parent = mapping[x]->parent;
        if (parent != x)
            parent = findSet(parent);

        return parent;
    }

    void combine(int x, int y)
    {

        Element *xp = mapping[findSet(x)];
        Element *yp = mapping[findSet(y)];

        if (xp->size < yp->size)
        {
            auto temp = xp;
            xp = yp;
            yp = temp;
        }

        yp->parent = xp->parent;
        xp->size = xp->size + yp->size;
    }
    int max()
    {
        int max = 0;
        for (auto item : mapping)
        {
            if (max < item.second->size)
                max = item.second->size;
        }
        return max;
    }
};
int longestConsecutive_uf(vector<int> &nums)
{
    UnionFind set(nums);
    for (auto num : nums)
    {
        if (set.present(num - 1) && set.findSet(num - 1) != set.findSet(num))
        {
            set.combine(num - 1, num);
        }
        if (set.present(num + 1) && set.findSet(num + 1) != set.findSet(num))
        {
            set.combine(num + 1, num);
        }
    }
    return set.max();
}

int longestConsecutive(vector<int> &nums)
{

    unordered_map<int, int> m;
    int maxcount = 0;
    for (auto num : nums)
    {
        if (m[num] == 0)
        {
            m[num] = m[num - 1] + m[num + 1] + 1;
            m[num - m[num - 1]] = m[num];
            m[num + m[num + 1]] = m[num];

            maxcount = max(maxcount, m[num]);

        }
    }
    return maxcount;
}
int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums);
}
