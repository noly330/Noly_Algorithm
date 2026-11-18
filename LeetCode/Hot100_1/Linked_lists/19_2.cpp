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

/// @brief 双指针法
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //也就是在头节点前面再搞一个节点，这样走x步，就位于第x个节点
        ListNode* slow = new ListNode(0,head);
        ListNode* fast = slow;

        

        //快指针先走n步，然后一起走，这样慢指针就会指向要删除节点的上一个
        for(int i = 1;i<=n;i++){
            fast = fast->next;
        }

        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow->next == head){
            return head->next;
        }

        slow->next = slow->next->next;

        return head;

    }
};