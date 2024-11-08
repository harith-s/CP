#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int size = 0;
        ListNode *temp = head;
        vector<ListNode*> split_list;
        while (temp != nullptr)
        {
            temp = head->next;
            size++;
        }
        int q = size / k;
        int r = size - q*k;
        vector<int> v(k, q);
        for (int i = 0; i < r; i++){
            v[i]++;
        }
        temp = head;
        

        for (int i = 0; i < v.size(); i++){
            int element_size = v[i];
            
            split_list.push_back(temp);
            for (int j = 0; j < element_size; j++){
                if ((j == element_size - 1) && temp){
                    ListNode *store_temp;
                    if (temp) {
                        store_temp = temp->next;
                        temp->next = nullptr;
                        temp = store_temp;
            }
                }
                else if (temp) temp = temp->next;
            }
            // ListNode *store_temp;
            // if (temp) {
            //     store_temp = temp->next;
            //     temp->next = nullptr;
            //     temp = store_temp;
            // }

        }
    }
};