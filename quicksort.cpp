#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int>& a, int start, int end)
{
    int pivot = a[start];
    int i = start - 1;
    int j = end + 1;

    while (true)
    {
        do
            i++;
        while (a[i] < pivot);
        do
            j--;
        while (a[j] > pivot);
        if (i >= j)
            return j;
        swap(a[i], a[j]);
    }
}
void quicksort(vector<int> &a, int start, int end)
{
    if (start >= end)
        return;
    int p = partition(a, start, end);
    quicksort(a, start, p);
    quicksort(a, p + 1, end);
}

int main()
{
    vector<int> a = {61, 51, 56, 69, 90, 84, 86, 45, 88, 61, 21};
    quicksort(a, 0, a.size() -1 );
    for (auto i : a)
    {
        cout << i << " ";
    }
}