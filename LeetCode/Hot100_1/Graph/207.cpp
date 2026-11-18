#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> e[numCourses];
        memset(e,0,sizeof(e));
        int rudu[numCourses];
        memset(rudu,0,sizeof(rudu));

        for(auto i : prerequisites){
            e[i[1]].push_back(i[0]);
            rudu[i[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(rudu[i] == 0){
                q.push(i);
            }
        }

        int ans = 0;
        while(q.size()){
            int now = q.front();
            q.pop();
            ans++;

            for(auto next : e[now]){
                rudu[next]--;
                if(rudu[next] == 0){
                    q.push(next);
                }
            }
        }

        return ans == numCourses;
    }
};