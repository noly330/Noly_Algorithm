#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//先用哈希表法，数学法，以后再自己推一下
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr = head;
        unordered_set<ListNode*> st;
        while(ptr){
            if(st.count(ptr)){
                return ptr;
            }
            
            st.insert(ptr);
            ptr = ptr->next;
        }

        return nullptr;
    }
};