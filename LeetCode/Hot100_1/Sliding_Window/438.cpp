#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(),k=p.size();
        vector<int> ans;
        vector<int> pp(26);
        vector<int> sp(26);
        if(n<k)
            return ans;
        for(int i = 0;i<k;i++){
            pp[p[i] - 'a']++;
        }

        for(int i=0;i<k;i++){
            sp[s[i]-'a']++;
        }

        if(pp==sp)
            ans.push_back(0);
        
            for(int i=1;i<n-k+1;i++){
                sp[s[i-1]-'a']--;
                sp[s[i+k-1]-'a']++;
                if(pp==sp)
                    ans.push_back(i);

            }

        return ans;
    }
};