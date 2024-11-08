#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &ost, vector<int> vector)
{
    for (auto i = vector.begin(); i != vector.end(); ++i)
    {
        ost << *i << ", ";
    }
    return ost;
}

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int remaining = 0;
    for (auto i = rolls.begin(); i != rolls.end(); ++i)
    {
        remaining += *i;
    }
    // remaining =;
    remaining = (rolls.size() + n) * mean - remaining;
    // the sum of n variables is this
    vector<int> result;
    result.reserve(n);
    int temp = n;
    for (int i = 0; i < n; i++)
    {
        result.push_back(1);
    }

    vector<int> empty;
    if ((temp < n) || (6 * n < temp))
        return empty;
    int index = 0;
    while (temp != remaining && index < n)
    {

        result[index] += 1;
        temp++;
        if (result[index] == 6)
            index++;
    }
    return result;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        int index1 = 0; int index2 = 0;
        // if (size1 == 0){
        //     if (size2 % 2 == 1) return nums2[size2/2];
        //     else {
        //         return (nums2[size2/2] + nums2[size2/2 - 1])/2
        //     }
        // }
        // else if (size2 == 0){
        //     if (size1 % 2 == 1) return nums1[size1/2];
        //     else {
        //         return (nums1[size1/2] + nums1[size1/2 - 1])/2
        //     }
        // }
        // else{
        //     if ((size1 + size2 ) % 2 == 1){
        //         while (index1 + index2)
        //     }
        // }
        vector<int> sorted(size1 + size2, 0);
        // sorted.reserve(size1 + size2);
        for (int i = 0; i < size1 + size2; i++){
            
            if ((index1 < size1 && index2 < size2)){
                if (nums1[index1] <= nums2[index2]){
                    sorted[i] = nums1[index1];
                    index1++;
                }
                else{
                    sorted[i] = nums2[index2];
                    index2++;
                }
            }
            else if (index2 < size2) {
                    sorted[i] = nums2[index2];
                    index2++;
            }
            else if (index1 < size1){
                    sorted[i] = nums1[index1];
                    index1++;
            }
        }
        

        int size = sorted.size();
        if (size % 2 == 1) return sorted[size/2];
        else return (sorted[size/2] + sorted[(size/2) - 1])/2;
        
    }
int main()
{
    vector<int> rolls, rols;
    rolls.push_back(1);
    rolls.push_back(3);
    rolls.push_back(6);
    rolls.push_back(9);

    rols.push_back(2);
    rols.push_back(4);
    rols.push_back(5);
    rols.push_back(7);


    vector<int> result;
    result = missingRolls(rolls, 6, 4);
    cout << findMedianSortedArrays(rols, rolls);
    // cout << result;
}
