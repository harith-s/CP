#include <iostream>
#include <queue>
#include <set>

using namespace std;

class MedianFinder
{
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, std::greater<int>> pq_min;
    int qsize;
    int temp;

public:
    MedianFinder()
    {
        qsize = 0;
    }

    void addNum(int num)
    {
        if (pq_max.size() == 0 && pq_min.size() == 0)
        {
            pq_max.push(num);
            qsize++;
            return;
        }
        else if (pq_min.size() == 0)
        {
            if (num >= pq_max.top())
            {
                pq_min.push(num);
                qsize++;
                return;
            }
            else
            {
                pq_min.push(pq_max.top());
                pq_max.pop();
                pq_max.push(num);
                qsize++;
                return;
            }
        }
        if (pq_min.size() == pq_max.size())
        {
            if (pq_max.top() > num)
                pq_max.push(num);
            else
                pq_min.push(num);
        }
        else if (pq_min.size() > pq_max.size())
        {
            if (pq_min.top() < num)
            {
                pq_max.push(pq_min.top());
                pq_min.pop();
                pq_min.push(num);
            }
            else
                pq_max.push(num);
        }
        else if (pq_min.size() < pq_max.size())
        {
            if (pq_max.top() > num)
            {
                pq_min.push(pq_max.top());
                pq_max.pop();
                pq_max.push(num);
            }
            else
                pq_min.push(num);
        }

        qsize++;
    }

    double findMedian()
    {
        if (qsize % 2 == 0)
        {
            return (pq_min.top() + pq_max.top()) / 2.0;
        }
        else
        {
            return pq_min.size() > pq_max.size() ? pq_min.top() : pq_max.top();
        }
    }
};

int main()
{
    MedianFinder m;
    // m.addNum(6);
    // cout << m.findMedian() << endl;
    // m.addNum(10);
    // cout << m.findMedian() << endl;
    // m.addNum(2);
    // cout << m.findMedian() << endl;
    // m.addNum(6);
    // cout << m.findMedian() << endl;
    // m.addNum(5);
    // cout << m.findMedian() << endl;
    // m.addNum(0);
    // m.addNum(6);
    // m.addNum(3);
    // m.addNum(1);
    // m.addNum(0);
    // m.addNum(0);
    vector<int> v = {40, 12, 16, 14, 35, 19, 34, 35, 28, 35, 26, 6, 8, 2, 14, 25, 25, 4, 33, 18, 10, 14, 27, 3, 35, 13, 24, 27, 14, 5, 0, 38, 19, 25, 11, 14, 31, 30, 11, 31, 0};
    for (unsigned int i = 0; i < v.size(); i++)
    {
        m.addNum(v[i]);
        int j = 0;
    }
}