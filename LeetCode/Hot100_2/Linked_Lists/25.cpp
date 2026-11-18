
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

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while(head){
            ListNode* tail = pre;
            for(int i = 0;i<k;i++){
                tail = tail->next;
                if(!tail){
                    return hair->next;
                }
            }

            ListNode* nex = tail->next;
            pair<ListNode*,ListNode*> result = myReverse(head,tail);

            head = result.first;
            tail = result.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
        
    }

    pair<ListNode*,ListNode*> myReverse(ListNode* head,ListNode* tail){
        ListNode* pre = tail->next;
        ListNode* p = head;

        while(pre != tail){
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }   

        return {tail,head};
    }
};