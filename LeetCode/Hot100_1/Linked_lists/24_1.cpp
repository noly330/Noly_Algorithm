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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* node = head;
        ListNode* preNode = nullptr;
        ListNode* returnHead = nullptr;

        if(node == nullptr){
            return nullptr;
        }
        if(node->next == nullptr){
            return node;
        }
        while(node != nullptr){
            if(node == head && node->next !=nullptr){
                returnHead = node->next;
                SwapListNode(node,node->next,nullptr);

                preNode = node;
                node = node->next;

                continue;
            }

            if(node->next != nullptr){
                SwapListNode(node,node->next,preNode);
                preNode=node;
                node=node->next;
                continue;
            }

            break;

        }

        return returnHead;
    }

    void SwapListNode(ListNode* a,ListNode* b,ListNode* pre){
        a->next = b->next;
        b->next = a;
        if(pre != nullptr)
            pre->next = b;
    }
};