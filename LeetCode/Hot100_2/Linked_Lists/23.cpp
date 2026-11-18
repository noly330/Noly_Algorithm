#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//TODO:学习O(1)空间复杂度
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> a;
        if(lists.size() == 0){
            return nullptr;
        }
        for(int i = 0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head){
                a.push_back(head->val);
                head = head->next;
            }
        }

        sort(a.begin(),a.end());
        ListNode* hair = new ListNode(0);
        ListNode* node = new ListNode(-1);
        hair->next = node;

        if(a.size() == 0){
            return nullptr;
        }
        for(int i = 0;i<a.size();i++){
            node->val = a[i];
            if(i!=a.size()-1){
                node->next = new ListNode(0);
            }
            node = node->next;
        }

        

        return hair->next;
    }
};