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
    
    void dfs(int node, int p, vector<int> & f, vector<int> & g) {
        
        int max_1 = 0, max_2 = 0;
        for(int nbr : l[node]) {
            if(nbr != p) {
                dfs(nbr, node, f, g);
                
                g[node] = max(g[node], g[nbr] + 1);
                f[node] = max(f[node], f[nbr]);
                if(g[nbr] + 1 > max_1) {
                    max_2 = max_1;
                    max_1 = g[nbr] + 1;
                }
                else if(g[nbr] + 1 > max_2) {
                    max_2 = g[nbr] + 1;
                }
            }
        }
        
        f[node] = max_1 + max_2;
    }
};

int main() {
    Graph adj(8);
    adj.addEdge(1,2);
    adj.addEdge(1,3);
    adj.addEdge(1,4);
    adj.addEdge(2,5);
    adj.addEdge(3,6);
    adj.addEdge(4,7);
    
    vector<int> f(8, 0);
    vector<int> g(8, 0);
    adj.dfs(1, 0, f, g);
    cout<<f[1]<<endl;
}