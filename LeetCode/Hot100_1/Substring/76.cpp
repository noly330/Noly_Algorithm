#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> tt;
        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++)
        {
            tt[t[i]]++;
        }

        int l = 0, r = 0;
        mp[s[l]]++;

        string ans = "";
        int minlen = INT_MAX;

        while (l < s.size() && r < s.size())
        {
            if (isSub(mp, tt))
            {
                int size = r - l + 1;
                if (size < minlen)
                {
                    ans = s.substr(l, r - l + 1);
                    minlen = size;
                }

                mp[s[l]]--;
                l++;
            }
            else
            {
                r++;

                if (r < s.size())
                    mp[s[r]]++;
            }
        }

        return ans;
    }

    bool isSub(unordered_map<char, int> a, unordered_map<char, int> b)
    {

        bool res = true;
        for (auto bb : b)
        {
            if (a[bb.first] < bb.second)
            {
                res = false;
            }
        }

        return res;
    }
};