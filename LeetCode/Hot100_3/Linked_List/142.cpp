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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;

        while(head){
            if(head == nullptr){
                return nullptr;
            }
            if(st.count(head)){
                return head;
            }
            st.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};


