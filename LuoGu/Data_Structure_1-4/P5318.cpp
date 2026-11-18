#include<bits/stdc++.h>
using namespace std;


const int N =1e5+10;
int n,m;

vector<int> e[N];
vector<int> ans_dfs;
vector<int> ans_bfs;
int st1[N];
int st2[N];


void dfs(int start){
    ans_dfs.push_back(start);
    st1[start] = 1;
    for(int i =0;i<e[start].size();i++){
        if(st1[e[start][i]] == 1)  continue;
        dfs(e[start][i]);
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    st2[x] =1;
    while(q.size()){
        int now = q.front();
        q.pop();
        ans_bfs.push_back(now);
        for(auto next : e[now]){
            if(st2[next] == 1)  continue;

            q.push(next);
            st2[next] = 1;
        }
    }
}

void Solove(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end());
    }

    dfs(1);
    bfs(1);

    for(int i=0;i<ans_dfs.size();i++){
        cout<<ans_dfs[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<ans_bfs.size();i++){
        cout<<ans_bfs[i]<<" ";
    }
}

int main(){

    Solove();

    return 0;

}