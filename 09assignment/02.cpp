#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l; // int *arr
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
        // arr = new int[V]  //intializing dynamic array
    }

    void addEdge(int u , int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int u , vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for(int v:l[u]) {
            if(!vis[v]) {
                dfsHelper(v , vis);
            }
        }
    }

    void dfs() {
        int u = 0;
        vector<bool> vis(V , false);

        dfsHelper(u , vis);
        cout << endl;
    }
};

int main() {
    
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.dfs();
    return 0;
}