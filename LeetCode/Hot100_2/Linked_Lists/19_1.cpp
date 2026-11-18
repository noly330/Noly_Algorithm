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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 使用哑节点处理边界情况
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        dfs(dummy, n);
        return dummy->next;
    }


    int dfs(ListNode* head,int n){
        if(head == nullptr){
            return 0;
        }

        int depth = dfs(head->next,n) + 1;

        if(depth == n+1){
            
            head->next = head->next->next;
            
        }

        return depth;
    }
};