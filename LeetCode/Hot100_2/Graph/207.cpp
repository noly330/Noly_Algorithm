#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> e[numCourses];
        vector<int> ru(numCourses,0);
        int m = prerequisites.size();

        if(m == 0){
            return true;
        }
        
        for(int i = 0;i<m;i++){
            e[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ru[prerequisites[i][0]]++;
        }

        queue<int> q;
        int sum = 0;
        for(int i = 0;i<ru.size();i++){
            if(ru[i] == 0){
                q.push(i);
                sum++;
            }
        }

        
        while(q.size()){
            int x = q.front();
            q.pop();
            for(auto xx : e[x]){
                ru[xx]--;
                if(ru[xx] == 0){
                    q.push(xx);
                    sum++;
                }
            }
        }

        return  sum == numCourses;
    }
};