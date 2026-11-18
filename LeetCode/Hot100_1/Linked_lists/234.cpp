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
        vector<int> arr;
        ListNode * curr = head;
        while(curr){
            arr.emplace_back(curr->val);
            curr = curr->next;
        }
        
        int n = arr.size();
        int l = 0,r=n-1;
        while(l<r){
            if(arr[l] != arr[r]){
                return false;
            }
            l++,r--;
        }

        return true;

        
    }
};