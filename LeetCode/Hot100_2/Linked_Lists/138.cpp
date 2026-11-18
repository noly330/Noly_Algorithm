#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:

    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(!cachedNode.count(head)){
            Node* newHead = new Node(head->val);
            cachedNode[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random);
        }

        return cachedNode[head];

    }
};