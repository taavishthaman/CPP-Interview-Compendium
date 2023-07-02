#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    list<int> * l;
    int V;
    
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    int vertexCoverDp(int node, bool take, int parent, vector<vector<int>> & dp) {
        
        if(dp[node][take] != -1) {
            return dp[node][take];
        }
        
        int ans = take;
        
        for(int nbr : l[node]) {
            if(nbr != parent) {
                if(take) {
                    ans += min(vertexCoverDp(nbr, 0, node, dp), vertexCoverDp(nbr, 1, node, dp));
                } else {
                    ans += vertexCoverDp(nbr, 1, node, dp);
                }
            }
        }
        
        return dp[node][take] = ans;
    }

    int vertexCover() {
        vector<vector<int>> dp(V+1, vector<int>(2, -1));
        return min(vertexCoverDp(1, 0, 0, dp), vertexCoverDp(1, 1, 0, dp));
    }
    
    void vertexCoverDfs(int node, int p, vector<vector<int>> & dp) {
        dp[node][0] = 0;
        dp[node][1] = 1;
        
        for(int nbr : l[node]) {
            if(nbr != p) {
                //First DFS
                vertexCoverDfs(nbr, node, dp);
                //Then fill values
                dp[node][0] += dp[nbr][1];
                dp[node][1] += min(dp[nbr][0], dp[nbr][1]);
            }
        }
    }
    
    int dfs() {
        vector<vector<int>> dp(V+1, vector<int>(2, 0));
        vertexCoverDfs(1, 0, dp);
        return min(dp[1][0], dp[1][1]);
    }

    int vertexCoverBfs(vector<vector<int>> & dp) {
        queue<int> q;
        vector<bool> visited(V+1, false);
        
        for(int i=0; i<=V; i++) {
            if(l[i].size() == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        int root;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            root = cur;
            dp[cur][0] = 0;
            dp[cur][1] = 1;
            for(int nbr : l[cur]) {
                if(visited[nbr]) {
                    dp[cur][0] += dp[nbr][1];
                    dp[cur][1] += min(dp[nbr][0], dp[nbr][1]);
                    
                } else {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        
        return min(dp[root][0], dp[root][1]);
    }
    
    int bfs() {
        vector<vector<int>> dp(V+1, vector<int>(2, 0));
        return vertexCoverBfs(dp);
    }
};

int main() {
    int N = 7;
    Graph g(N+1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    g.addEdge(4,7);
    // cout<<g.vertexCover()<<endl;
    cout<<g.dfs()<<endl;
}