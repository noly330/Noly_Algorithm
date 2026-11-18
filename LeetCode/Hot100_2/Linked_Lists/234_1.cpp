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
    bool isPalindrome(ListNode *head)
    {
        vector<int> a;

        while(head){
            if(head == nullptr){
                break;
            }
            a.push_back(head->val);
            head=head->next;
        }

        int l = 0; int r = a.size() - 1;
        while(l<r){
            if(a[l] != a[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};