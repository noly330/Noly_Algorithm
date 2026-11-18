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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode*> visited;
        ListNode *p = head;
        while (p != nullptr)
        {
            if(visited.count(p)){
                return true;
            }
            visited.insert(p);
            p = p->next;
        }
        return false;
    }
};
