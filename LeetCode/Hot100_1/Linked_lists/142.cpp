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
    ListNode *detectCycle(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr){
            if(fast == nullptr || fast->next == nullptr){
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode * ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return fast;
    }
};
