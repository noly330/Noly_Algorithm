#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }

        ListNode* head = list1;
        if(list1->val>list2->val)
            head = list2;
        if(list1 == nullptr)
            head = list2;

        ListNode* next;
        if(list1->val<=list2->val){
            next = list1->next;
            list1->next = mergeTwoLists(next,list2);
            
        }
        else{
            next = list2->next;
            list2->next = mergeTwoLists(list1,next);
            
        }

        return head;
    }
};