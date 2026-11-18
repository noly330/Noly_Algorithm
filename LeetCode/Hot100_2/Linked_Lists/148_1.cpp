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
//TODO:学习空间复杂度O(1)的解法
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> a;
        if(head == nullptr){
            return nullptr;
        }
        while(head){
            a.push_back(head->val);
            head = head->next;
        }

        sort(a.begin(),a.end());
        ListNode* hair = new ListNode(0);
        ListNode* p = new ListNode(0);
        hair->next = p;
        for(int i = 0;i<a.size();i++){
            p->val = a[i];
            if(i!= a.size()-1)
                p->next = new ListNode(0);
            p = p->next;
        }

        return hair->next;
    }
};