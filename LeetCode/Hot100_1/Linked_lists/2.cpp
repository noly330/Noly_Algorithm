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
        ListNode *ans = nullptr;
        ListNode *ptr = nullptr;
        int carry = 0;
        while(l1 || l2){
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if(ans == nullptr){
                ans = ptr = new ListNode(sum %10);
            }
            else{
                ptr->next = new ListNode(sum % 10);
                ptr = ptr->next;
            }

            carry = sum/10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }

            
        }
        if(carry > 0){
            ptr->next = new ListNode(carry);
        }

        return ans;
    }
};