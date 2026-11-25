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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* ans = new ListNode(0);
        ListNode* current = ans;
        bool isplus = false;
        while(l1||l2){
            int x1 = l1 != nullptr ? l1->val : 0;
            int x2 = l2 != nullptr ? l2->val : 0;
            int x = x1+x2;
            if(isplus){
                x++;
                isplus = false;
            }
            if(x >=10){
                x = x%10;
                isplus = true;
            }
            
            current->next = new ListNode(x);
            current = current->next;
            if(l1!=nullptr){
                l1 = l1->next;
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }
        if(isplus){
            current->next = new ListNode(1);
        }
        return ans->next;
    }
};