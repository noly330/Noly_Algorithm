#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> mpp;
        unordered_map<char, int> mps;
        vector<int> ans;

        int np = p.size();
        int ns = s.size();
        if (s.size() < p.size())
        {
            return ans;
        }

        for (int i = 0; i < p.size(); i++)
        {
            mpp[p[i]]++;
        }

        for (int i = 0; i < p.size(); i++)
        {
            mps[s[i]]++;
        }


        if (mps == mpp)
            {
                ans.push_back(0);
            }

        for (int l = 1; l + np - 1< ns; l++)
        {
            mps[s[l-1]]--;
            mps[s[l+np-1]]++;
            if(mps[s[l-1]] == 0){
                mps.erase(s[l-1]);
            }
            if (mps == mpp)
            {
                ans.push_back(l);
            }

        }
        return ans;

    }
};