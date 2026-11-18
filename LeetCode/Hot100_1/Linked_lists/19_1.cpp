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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        stack<ListNode *> stk;
        ListNode *node = head;

        while (node != nullptr)
        {
            stk.push(node);
            node = node->next;
        }
        if(n == stk.size()){
            return head->next;
        }
        //弹出n次
        for(int i =1;i<=n;i++){
            stk.pop();
        }

        
        if(stk.top() != nullptr){
            ListNode* a = stk.top();
            a->next = a->next->next;
        }
        

        return head;

    }
};