#include <bits/stdc++.h>
using namespace std;



struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* head = headA;
        unordered_set<ListNode*> st;
        while(head!=nullptr){
            st.insert(head);
            head = head->next;
        }

        head = headB;

        while(head!=nullptr){
            if(st.count(head)){
                return head;
            }

            head = head->next;
        }

        return nullptr;
    }
};